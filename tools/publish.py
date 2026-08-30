
import sys
import os
import os.path
import subprocess

if sys.platform == "win32":
    import winreg

def find_bi_tools():
    reg = winreg.ConnectRegistry(None, winreg.HKEY_CURRENT_USER)
    try:
        k = winreg.OpenKey(reg, r"Software\bohemia interactive\arma 3 tools")
        arma3tools_path = winreg.QueryValueEx(k, "path")[0]
        winreg.CloseKey(k)
    except:
        raise Exception("BadTools","Arma 3 Tools are not installed correctly or the P: drive needs to be created.")

    publisher_path = os.path.join(arma3tools_path, "Publisher", "PublisherCmd.exe")

    if os.path.isfile(publisher_path):
        return publisher_path
    else:
        raise Exception("BadTools","Arma 3 Tools are not installed correctly or the P: drive needs to be created.")


def publishFolder(folder,modID,changeNotes):
    cmd = [publisherTool_path, "update", "/id:{}".format(modID), "/changeNoteFile:{}".format(changeNotes), "/path:{}".format(folder)]

    print ("running: {}".format(cmd))

    print("")
    print("Publishing folder {} to workshop ID {}".format(folder,modID))
    print("")
    if (not do_publish):
        print("Just doing test build")
        return
    ret = subprocess.call(cmd)
    if ret != 0:
        print("publisher faild with code {}".format(ret))
        raise Exception("Publisher","Publisher had problems")


#GLOBALS
project_base_path = os.path.dirname(os.path.dirname(os.path.realpath(__file__)))
release_dir = os.path.join(project_base_path,"releases")
project = "@potato"
publisherTool_path = find_bi_tools()
changelog_path = os.path.join(release_dir,"changelog.txt")
project_release_dir = os.path.join(release_dir, project)

do_publish = True
# do_publish = False #will let you just build dirs and test without running publisher


def main(argv):
    if not os.path.exists(project_release_dir):
        raise Exception("project_release_dir not found","Project not built or in wrong path")
    if not os.path.exists(publisherTool_path):
        raise Exception("publisherTool_path not found","Arma Tools not found")
    if not os.path.exists(changelog_path):
        raise Exception("changelog_path not found","Requires changelog.txt be present in the release dir")

    if do_publish:
        repl = input("\nThis will publish to steam, are you positive release dir has correct files? (y/n): ")
        if repl.lower() != "y":
            return 0

    publishFolder(project_release_dir, "2987557792", changelog_path)


if __name__ == "__main__":
    main(sys.argv)
