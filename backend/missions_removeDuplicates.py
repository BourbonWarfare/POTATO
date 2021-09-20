# PabstMirror - Cleans up old versions of missions

import os
import sys
import re
import shutil

path_missions = "E:\\BourbonWarfare\\ArmA3\\Master\\MPMissions"
path_dump = "E:\BourbonWarfare\ArmA3\Mission Backups\oldVersions"


def main(argv):
    print("\n\n--- Start -- {}".format(argv))
    if not os.path.isdir(path_missions): raise Exception("missing dir - {}".format(path_missions))
    if not os.path.isdir(path_dump): raise Exception("missing dir - {}".format(path_dump))

    missionVersions = {}
    missionsFound = []
    #  author_co40_mName_v1.torabora.pbo
    # (author_co40_mName)_v(1).(torabora).pbo
    versionPattern = re.compile("(.*)_v(\d*)\.(.*)\.pbo", re.IGNORECASE)

    for filename in os.listdir(path_missions):
        if (filename.startswith("ZKEEP")): continue
        versionInfo = versionPattern.findall(filename)
        if (versionInfo):
            mission, version, map = versionInfo[0]
            key = mission + map
            version = int(version)
            bestVersion = -999
            if key in missionVersions:
                bestVersion = missionVersions[key]
            if version > bestVersion:
                missionVersions[key] = version
            missionsFound.append((key, version, filename))

    for key, version, filename in missionsFound:
        bestVersion = missionVersions[key]
        if version != bestVersion:
            print(f"cleaning up {filename} because {bestVersion} is better")
            path_source = os.path.join(path_missions, filename)
            path_dest = os.path.join(path_dump, filename)
            shutil.move(path_source, path_dest)

    print(f"Done")
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))
