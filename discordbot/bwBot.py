import discord
from discord.ext import tasks, commands
from steam import game_servers
import socket
import subprocess
import datetime

CHANNEL_BOT = 585642663202783236
ALL_SERVERS_STEAM = [  # Note: port numbers are +1 from the arma server (e.g. Game Port: 2303, Steam Query Port: 2304)
    ["Main", ("104.128.50.152", 2304)],
    ["Training", ("104.128.50.152", 2370)],
    ["Offnight", ("104.128.50.152", 2486)],
]


class NotInBotChannel(commands.CheckFailure):
    pass


def steam_checkServer(serverNick, server_addr):
    """Checks server status via steam"""
    ret = ""
    try:
        info = game_servers.a2s_info(server_addr, timeout=1)
        ret = "{}: [{} Players] [{} {}]".format(serverNick, info["players"], info["game"], info["map"])
    except (ConnectionResetError, socket.timeout) as e:
        print(" WARNING: steam_checkServer {} = {}".format(serverNick, e))
        ret = "{}: OFFLINE".format(serverNick)
    print(" TRACE:[steam_checkServer({},{})]: {}".format(serverNick, server_addr, ret))
    return ret


def steam_getPlayerCount(server_addr):
    """Gets player count via steam"""
    ret = -1
    try:
        info = game_servers.a2s_info(server_addr, timeout=1)
        ret = info["players"]
    except (ConnectionResetError, socket.timeout) as e:
        # print(" WARNING: steam_getPlayerCount {} = {}".format(server_addr, e))
        pass
    # print(" TRACE:[steam_getPlayerCount({})]: {}".format(server_addr, ret))
    return ret


class cog_update_bot_status(commands.Cog):
    def __init__(self, bot):
        self.bot = bot
        self.update_status.start()

    def cog_unload(self):
        self.update_status.cancel()

    @tasks.loop(seconds=60)
    async def update_status(self):
        status = ""
        for (name, addr) in ALL_SERVERS_STEAM:
            player_count = steam_getPlayerCount(addr)
            if (name == "Main") or (player_count > 0):
                status += "[{}: {}]".format(name[0], player_count)
        await self.bot.change_presence(activity=discord.Game(name=status))
        print(" TRACE: [status_cog]: {}".format(status))

    @update_status.before_loop
    async def wait_for_bot_to_ready(self):
        print(" [cog_update_bot_status] - Waiting for bot to become ready")
        await self.bot.wait_until_ready()


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
    print(" WARNING:[on_command_error: {}] {}: {}".format(error, ctx.author, ctx.message.content))
    await ctx.send("Invalid: {}".format(error))


@bot.command()
async def status(ctx):
    """Command prints status of arma servers"""
    print(" TRACE:[bot: status] {}: {}".format(ctx.author, ctx.message.content))
    for (name, addr) in ALL_SERVERS_STEAM:
        await ctx.send(steam_checkServer(name, addr))


@bot.command()
async def userinfo(ctx, member: discord.Member):
    """Command states when a member joined"""
    print(" TRACE:[bot: userinfo] {}: {}".format(ctx.author, ctx.message.content))
    msg = "{0.display_name} joined on {0.joined_at} ({0._user})".format(member)
    await ctx.send(msg)


@bot.command()
async def spinup(ctx, *args):
    """Command starts up extra server [use with: training or offnight]"""
    print(" TRACE:[bot: spinup {}] {}: {}".format(args, ctx.author, ctx.message.content))
    server_type = "?"
    if len(args) > 0:
        server_type = args[0].lower()
    if server_type in ["training", "train", "t"]:
        await ctx.send("starting training server")
        print("Training.bat")
        subprocess.call([r"E:\BourbonWarfare\ArmA3\Master\@dedicated_server - Training.bat"], stdout=subprocess.DEVNULL)
    elif server_type in ["offnight", "oftnight", "on", "o"]:
        await ctx.send("starting offnight server")
        print("Offnight.bat")
        subprocess.call(
            [r"E:\BourbonWarfare\ArmA3\serverOffNight\@dedicated_server - Offnight.bat"], stdout=subprocess.DEVNULL
        )
    else:
        await ctx.send("Need type, use with: training or offnight")


@bot.command()
async def restart(ctx, *args):
    """Command force closes all arma servers (except public) and restarts Main and HC [use with force if needed]"""
    print(" TRACE:[bot: restart {}] {}: {}".format(args, ctx.author, ctx.message.content))
    player_count = steam_getPlayerCount(ALL_SERVERS_STEAM[0][1])
    is_forced = (len(args) > 0) and (args[0].lower() in ["force", "f"])
    if (player_count > 2) and not is_forced:
        await ctx.send("{} players online, use command with ' force' to continue")
        return
    await ctx.send("restarting")
    print("restart_server.bat")
    subprocess.call([r"E:\BourbonWarfare\ArmA3\Master\restart_server.bat"], stdout=subprocess.DEVNULL)


# @bot.command()
# async def publicrestart(ctx):
#     """Command restarts the public server [use with care]"""
#     print(" TRACE:[bot: publicrestart] {}: {}".format(ctx.author, ctx.message.content))
#     await ctx.send("restarting the public server")
#     subprocess.call([r"E:\BourbonWarfare\ArmA3\Master\public.bat"], stdout=subprocess.DEVNULL)


print("Starting {}".format(datetime.datetime.now()))
bot.add_cog(cog_update_bot_status(bot))
bot.run("")  # don't commit this lol
