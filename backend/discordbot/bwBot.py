import discord
from discord.ext import tasks, commands
from steam import game_servers
import socket
import subprocess
import datetime
import re
import bwBot_settings
from pathlib import Path

CHANNEL_LIST = bwBot_settings.CHANNEL_LIST
ALL_SERVERS_STEAM = bwBot_settings.ALL_SERVERS_STEAM

file_path = Path("E:\BourbonWarfare\gameservers\plugins\SGDArma3.cs\missions")
main_path = file_path / "main"
offnight_path = file_path / "offnight"

class NotInBotChannel(commands.CheckFailure):
    pass


def steam_checkServer(serverNick, server_addr):
    """Checks server status via steam"""
    ret = ""
    try:
        info = game_servers.a2s_info(server_addr, timeout=1)
        ret = "{}: [{} Players] [{} {}]".format(serverNick, info["players"], info["game"], info["map"])
    except (ConnectionResetError, socket.timeout) as e:
        # print(" TRACE: steam_checkServer {} = {}".format(serverNick, e))
        ret = "{}: OFFLINE".format(serverNick)
    print(" TRACE:[steam_checkServer({},{})]: {}".format(serverNick, server_addr, ret))
    return ret


def steam_getPlayerCount(server_addr):
    """Gets player count via steam (-1 indicates offline)"""
    ret = -1
    try:
        info = game_servers.a2s_info(server_addr, timeout=1)
        ret = info["players"]
    except (ConnectionResetError, socket.timeout) as e:
        # print(" TRACE: steam_getPlayerCount {} = {}".format(server_addr, e))
        pass
    # print(" TRACE:[steam_getPlayerCount({})]: {}".format(server_addr, ret))
    return ret


def check_rdp_state():
    """Checks state of RDP"""
    ret = "[?]"
    args = ["quser", bwBot_settings.SERVER_USERNAME]
    process = subprocess.run(args, capture_output=True)
    output = process.stdout.decode('utf-8')
    p = re.compile(r"\>[^\s]*[\s]*[^\s]*[\s]*[\d]*[\s]*([^\s]*)")
    x = re.search(p, output)

    if (x.group(1) == "Active"): ret = "[RDP]"
    if (x.group(1) == "Disc"): ret = ""
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
        status += check_rdp_state()
        for (name, addr) in ALL_SERVERS_STEAM:
            player_count = steam_getPlayerCount(addr)
            if (name == "Main") or (player_count != -1):
                status += "[{}: {}]".format(name[0], player_count)
        await self.bot.change_presence(activity=discord.Game(name=status))
        # print(" TRACE: [status_cog]: {}".format(status))

    @update_status.before_loop
    async def wait_for_bot_to_ready(self):
        print(" [cog_update_bot_status] - Waiting for bot to become ready")
        await self.bot.wait_until_ready()


bot = commands.Bot(command_prefix=commands.when_mentioned)


@bot.event
async def on_ready():
    print("Logged in as {}:{}".format(bot.user.name, bot.user.id))
    for channel in CHANNEL_LIST:
        print("Bot Active in Channel {}".format(bot.get_channel(channel)))
    print("------")


@bot.check
async def isSpecificChannel(ctx):
    """Checks the bot is called only from a specific channel"""
    if not ctx.channel.id in CHANNEL_LIST:
        raise NotInBotChannel("Only active in bot channel")
    return True


@bot.event
async def on_command_error(ctx, error):
    """Error handler for commands"""
    print(" WARNING:[on_command_error: {}] {}: {}".format(error, ctx.author, ctx.message.content))
    await ctx.send("Invalid: {}".format(error))

@bot.command()
async def userinfo(ctx, member: discord.Member):
    """Command states when a member joined"""
    print(" TRACE:[bot: userinfo] {}: {}".format(ctx.author, ctx.message.content))
    msg = "{0.display_name} joined on {0.joined_at} ({0._user})".format(member)
    await ctx.send(msg)

async def test(ctx, mission):
    name_list = mission.filename.split(".")
    if name_list[-1] == "pbo":
        print(f"Mission File Passed Testing. File [{mission.filename}]")
        return True
    else:
        await ctx.send(f":stop_sign: The file `{mission.filename}` is not a mission pbo")
        print(f"File failed testing. File [{mission.filename}]")
        return False

async def delete_file(fp):
    try:
        fp.unlink()
        print(f"File deleted at location [{fp}]")
    except OSError as e:
        print("Error: %s : %s" % (fp, e.strerror))

async def movefile(ctx, mission, mission_path, server_dest):
    if server_dest in ["session","main","s","m"]:
        server = "Main and Training"
        mission_dest_path = main_path / mission.filename
    elif server_dest in ["offnight","off","o"]:
        server = "Offnight"
        mission_dest_path = offnight_path / mission.filename
    else:
        raise TypeError(":stop_sign: Check you smelling, deleting uploaded file from server")
    try:
        (file_path / mission_path).rename(mission_dest_path)
        await ctx.send(f":white_check_mark: Mission file `{mission.filename}` successfully uploaded to the `{server}` server.")
        print(f"Mission file upload successful. Path [{mission_dest_path}]")
    except:
        raise TypeError(":stop_sign: File move failed for reasons. Likely because the file already exists.")

@bot.command()
async def upload(ctx, *args):
    attachments = ctx.message.attachments
    if len(args) > 0:
        server_dest = args[0].lower()
        if len(attachments) >  0:
            for mission in attachments:
                mission_path = file_path / mission.filename
                await mission.save(mission_path, seek_begin=True, use_cached=False)
                print(f"Attempting file upload process for [{mission.filename}] from user [{ctx.author}]")
                result = await test(ctx,mission)
                if result is True:
                    try:
                        await movefile(ctx, mission, mission_path, server_dest)
                    except Exception as e:
                        await ctx.send(f"{e}")
                        await delete_file(mission_path)
                else:
                    await delete_file(mission_path)
        else:
            await ctx.send(":stop_sign: There are no attachments to your message. Try again.")
    else:
        await ctx.send(":stop_sign: Please specify which server to upload to: 'Main' or 'Offnight' ")


print("Starting {}".format(datetime.datetime.now()))
bot.add_cog(cog_update_bot_status(bot))
bot.run(bwBot_settings.BOT_KEY)

