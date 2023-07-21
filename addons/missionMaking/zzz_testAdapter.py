import sys
import os

path_root = os.path.realpath(os.path.dirname(__file__))

cleanup_warning = False
if not os.path.isdir(os.path.join(path_root, "loadouts")):
    path_bwmf = os.path.join(os.path.dirname(os.path.dirname(os.path.dirname(path_root))), "bwmf")
    print(f"not in mission.sqm, trying bwmf path = {path_bwmf}")
    if not os.path.isdir(os.path.join(path_bwmf, "loadouts")):
        raise
    cleanup_warning = True
    path_root = path_bwmf


def main():
    loadout_files = []
    for root, dirnames, filenames in os.walk(os.path.join(path_root, "loadouts")):
        with os.scandir(root) as it:
            for file in it:
                if file.is_file() and os.stat(file).st_size > 5000:  # this is dumb but works
                    if (file.name.startswith("blankForArsenal")): continue
                    if (file.name.startswith("DoNoUse")): continue
                    loadout_files.append(file.path)

    print(f"Checking {len(loadout_files)} loadout_files")
    # loadout_files = [loadout_files[0]]  # debug - just do first one

    path_d_ext = os.path.join(path_root, "description.ext")
    if (not os.path.exists(path_d_ext)): raise Exception("no description.ext")
    with open(path_d_ext, 'a') as f:
        f.write(f"\n// Loadout Test Adapter (this should not be in released missions or cleanup may not work)\n")
        f.write(f"class potato_checkLoadouts {{\n")

        for index, path_loadout in enumerate(loadout_files):
            loadout_name = os.path.basename(path_loadout).split(".")[0]
            loadout_relPath = os.path.relpath(path_loadout, path_root)
            print(f"loadout: {index}: {loadout_name}")

            f.write(f"\n")
            f.write(f"class {loadout_name} {{ // {index}\n")
            f.write(f"#include \"Loadouts\west_gear.hpp\"\n")
            f.write(f"#include \"{loadout_relPath}\"\n")
            f.write(f"}};\n")

        f.write(f"}};\n")

    if (cleanup_warning):
        print("WARNING: potato_checkLoadouts added directly to bwmf, make sure to cleanup")
    return 0


if __name__ == "__main__":
    sys.exit(main())
