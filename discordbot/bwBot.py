import discord
from discord.ext import commands
from steam import game_servers
import socket
import subprocess

CHANNEL_BOT = 585642663202783236


class NotInBotChannel(commands.CheckFailure):
    pass


def steam_checkServer(serverNick, server_addr):
    """Checks server status via steam"""
    ret = ""
    try:
        info = game_servers.a2s_info(server_addr, timeout=1)
        ret = "{}: [{} Players] [{} {}]".format(serverNick, info["players"], info["game"], info["map"])
    except (ConnectionResetError, socket.timeout) as e:
        print("Error when checking on server {} = {}".format(serverNick, e))
        ret = "{}: OFFLINE".format(serverNick)
    print("[steam_checkServer({},{})]: {}".format(serverNick, server_addr, ret))
    return ret


bot = commands.Bot(command_prefix=commands.when_mentioned)


@bot.event
async def on_ready():
    print("Logged in as {}:{}".format(bot.user.name, bot.user.id))
    print("Bot Active in Channel {}".format(bot.get_channel(CHANNEL_BOT)))
    print("------")


@bot.check
async def isSpecificChannel(ctx):
    """Checks the bot is called only from a specific channel"""
    if ctx.channel != bot.get_channel(CHANNEL_BOT):
        raise NotInBotChannel("Only active in bot channel")
    return True


@bot.event
async def on_command_error(ctx, error):
    """Error handler for commands"""
    print("[on_command_error: {}] {}: {}".format(error, ctx.author, ctx.message.content))
    await ctx.send("Invalid: {}".format(error))


@bot.command()
async def status(ctx):
    """Command prints status of arma servers"""
    print("[bot: status] {}: {}".format(ctx.author, ctx.message.content))
    # Note: port numbers are +1 from the arma server (e.g. Game Port: 2303, Steam Query Port: 2304)
    await ctx.send(steam_checkServer("Main", ("104.128.50.152", 2304)))
    await ctx.send(steam_checkServer("Training", ("104.128.50.152", 2370)))
    await ctx.send(steam_checkServer("Offnight", ("104.128.50.152", 2486)))


@bot.command()
async def userinfo(ctx, member: discord.Member):
    """Command states when a member joined"""
    print("[bot: userinfo] {}: {}".format(ctx.author, ctx.message.content))
    msg = "{0.display_name} joined on {0.joined_at} ({0._user})".format(member)
    await ctx.send(msg)


@bot.command()
async def spinup(ctx):
    """Command starts up extra arma training server"""
    print("[bot: spinup] {}: {}".format(ctx.author, ctx.message.content))
    await ctx.send("starting training server")
    subprocess.call([r"E:\ArmA3\Master\@dedicated_server - Training.bat"])


@bot.command()
async def spinupOffnight(ctx):
    """Command starts up offnight server"""
    print("[bot: spinup] {}: {}".format(ctx.author, ctx.message.content))
    await ctx.send("starting offnight server")
    subprocess.call([r"E:\ArmA3\Master\@dedicated_server - Offnight.bat"])


@bot.command()
async def restart(ctx):
    """Command force restarts ALL arma servers [use with care]"""
    print("[bot: restart] {}: {}".format(ctx.author, ctx.message.content))
    await ctx.send("restarting")
    subprocess.call([r"E:\ArmA3\Master\restart_server.bat"])


bot.run("")  # don't commit this lol
