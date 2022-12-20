# verify mods

import os
import sys
import subprocess
import concurrent.futures
import argparse
import time

path_script = os.path.dirname(os.path.realpath(__file__))

path_DSCheckSignatures = os.path.join(path_script, "DSCheckSignatures.exe")
if not os.path.isfile(path_DSCheckSignatures): raise Exception(f"missing - {path_DSCheckSignatures}")

path_mods_primary = r"E:\BourbonWarfare\arma\ArmaMods\primary_modset"
if not os.path.isdir(path_mods_primary): raise Exception(f"missing {path_mods_primary}")
path_mods_staging = r"E:\BourbonWarfare\arma\ArmaMods\primary_staging"
if not os.path.isdir(path_mods_staging): raise Exception(f"missing {path_mods_staging}")


def verify_addon(path_addon, deep):
    folder_addons = os.path.join(path_addon, "addons")
    if not os.path.isdir(folder_addons): print(f"Warning: missing addons {folder_addons}")
    folder_keys = os.path.join(path_addon, "keys")
    if not os.path.isdir(folder_keys): print(f"Warning: missing keys {folder_keys}")

    cmd = [path_DSCheckSignatures]
    if (deep): cmd.append("-deep")
    cmd.append(folder_addons)
    cmd.append(folder_keys)
    ret = subprocess.call(cmd)
    return (os.path.basename(path_addon), ret)


def main(argv):
    print(f"--- Start --")
    os.chdir(path_script)

    parser = argparse.ArgumentParser(prog="verify")
    parser.add_argument("-d", "--deep", action="store_true")
    parser.add_argument("-p", "--primary", action="store_true")
    args = parser.parse_args()

    path_mods = path_mods_primary if args.primary else path_mods_staging

    with concurrent.futures.ThreadPoolExecutor(max_workers=12) as executor:
        addon_checks = []
        for folder in os.scandir(path_mods):
            if (folder.is_dir() and os.path.basename(folder).startswith("@")):
                addon_checks.append(executor.submit(verify_addon, folder.path, args.deep))
        print(f" started {len(addon_checks)} checks")
        executor.shutdown()
        time.sleep(0.1)
        print(f" finished")
        for future in addon_checks:
            addon, ret = future.result()
            print(f"{addon} = {ret}")

    print("--- End --")
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))


# bisign is supose to be better but complains about many older pbos that arma loads just fine
# below is unfinished wip on using it to test pbo sigs

# path_bisign = os.path.join(path_start, "bisign.exe")
# if not os.path.isfile(path_bisign): raise Exception(f"missing - {path_bisign}")

# def verify_addon_bisign(path_addon):
#     folder_addons = os.path.join(path_addon, "addons")
#     if not os.path.isdir(folder_addons): raise Exception(f"mod missing addons")
#     folder_keys = os.path.join(path_addon, "keys")
#     if not os.path.isdir(folder_keys): raise Exception(f"mod missing keys")

#     all_keys = os.scandir(folder_keys)
#     # if (len(all_keys) != 1): raise Exception(f" Keys not singualr")
#     path_bikey = next(all_keys).path
#     print(f" using {path_bikey}")

#     for f in os.scandir(folder_addons):
#         if (f.is_file() and f.path.endswith(".pbo")):
#             ret = subprocess.call([path_bisign, "verify", path_bikey, f.path])
#             print(f" return = {ret}")
#             if (ret != 0): raise Exception(" err sign {ret}")
#             return
