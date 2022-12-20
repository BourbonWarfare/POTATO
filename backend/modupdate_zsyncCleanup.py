# cleans up zync files (for moving from staging to base)
import os
import sys
import time

path_mods_staging = r"E:\BourbonWarfare\arma\ArmaMods\primary_staging"
if not os.path.isdir(path_mods_staging): raise Exception(f"missing {path_mods_staging}")


def main(argv):
    print(f"--- Start --")

    for root, _dirs, files in os.walk(path_mods_staging):
        for file in files:
            if file.endswith(".zsync"): os.remove(os.path.join(root, file))

    print("--- End --")
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))
