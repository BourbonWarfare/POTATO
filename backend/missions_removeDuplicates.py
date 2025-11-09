# PabstMirror - Cleans up old versions of missions
# B:\python\3.12\python.exe .\missions_removeDuplicates.py

import os
import sys
import re
import shutil


script_dir = os.path.dirname(os.path.abspath(__file__))
path_missions = os.path.join(script_dir, "main")
path_duplicates = os.path.join(script_dir, "_duplicates")
path_bad_names = os.path.join(script_dir, "_bad_names")


def main(argv):
    print("\n\n--- Start -- {}".format(argv))
    if not os.path.isdir(path_missions): raise Exception(f"missing dir - {path_missions}")
    if not os.path.isdir(path_duplicates): raise Exception(f"missing dir - {path_duplicates}")
    if not os.path.isdir(path_bad_names): raise Exception(f"missing dir - {path_bad_names}")

    missionVersions = {}
    missionsFound = []
    #  author_co40_mName_v1.torabora.pbo
    # (author_co40_mName)_v(1).(torabora).pbo
    versionPattern = re.compile(r"(.*)_v(\d*)\.(.*)\.pbo", re.IGNORECASE)

    for filename in os.listdir(path_missions):
        filename_lower = filename.lower()
        if (filename_lower.startswith("z") and not filename_lower.startswith("zoh")): continue
        versionInfo = versionPattern.findall(filename_lower)
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
        else:
            print(f"Unrecognized mission file: {filename}")
            path_source = os.path.join(path_missions, filename)
            path_dest = os.path.join(path_bad_names, filename)
            # shutil.move(path_source, path_dest)

    for key, version, filename in missionsFound:
        bestVersion = missionVersions[key]
        if version != bestVersion:
            print(f"cleaning up {filename} because {bestVersion} is better")
            path_source = os.path.join(path_missions, filename)
            path_dest = os.path.join(path_duplicates, filename)
            shutil.move(path_source, path_dest)

    print(f"Done")
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))
