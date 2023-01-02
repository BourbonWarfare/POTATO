# PabstMirror - signs mod folders
# Usage `py ./modupdate_signFolder.py "@miscmods"`  (note: need quotes on folder because @symbol causes problems)

import os
import sys
import subprocess
import datetime
import shutil
import concurrent.futures
import argparse

key_prefix = "BW"

path_script = os.path.dirname(os.path.realpath(__file__))

path_private_keys = os.path.join(path_script, "private_keys")
if not os.path.isdir(path_private_keys): raise Exception(f"missing {path_private_keys}")
path_DSCreateKey = os.path.join(path_script, "DSCreateKey.exe")
if not os.path.isfile(path_DSCreateKey): raise Exception(f"missing - {path_DSCreateKey}")
path_DSSignFile = os.path.join(path_script, "DSSignFile.exe")
if not os.path.isfile(path_DSSignFile): raise Exception(f"missing - {path_DSSignFile}")

path_mods_primary = r"E:\BourbonWarfare\arma\ArmaMods\primary_modset"
if not os.path.isdir(path_mods_primary): raise Exception(f"missing {path_mods_primary}")
path_mods_staging = r"E:\BourbonWarfare\arma\ArmaMods\primary_staging"
if not os.path.isdir(path_mods_staging): raise Exception(f"missing {path_mods_staging}")


def cleanup(path_mod, key_name_base, reuse_key):
    print("cleanup")
    if not reuse_key:
        for file in os.scandir(path_private_keys):
            if file.path.startswith(key_name_base):
                print(f" removing private {file}")
                os.remove(file)
    key_count = 0
    for root, _dirs, files in os.walk(path_mod):
        for file in files:
            if file.endswith(".bisign"):
                key_count = key_count + 1
                os.remove(os.path.join(root, file))
            if (not reuse_key) and file.endswith(".bikey"):
                print(f" removing {file}")
                os.remove(os.path.join(root, file))
    print(f" removing {key_count} bisigns")


def get_key(path_mod, key_name_base, reuse_key):
    print(f"get_key")
    path_key_private = None
    if reuse_key:  # Use existing key
        for file in os.scandir(path_private_keys):
            if file.path.startswith(key_name_base) and file.endswith(".biprivatekey"):
                path_key_private = file
                print(f" found existing key: {path_key_private}")
        if (path_key_private == None): raise Exception(f"Cannnot find existing .biprivatekey for {key_name_base}")
    else:  # Generate new private key
        date = datetime.datetime.today().strftime("%y_%m")
        key_name_date = f"{key_name_base}-{date}"
        ret = subprocess.call([path_DSCreateKey, key_name_date])
        if (ret != 0): raise Exception("err keygen {ret}")
        path_key_public = os.path.join(path_private_keys, f"{key_name_date}.bikey")
        path_key_private = os.path.join(path_private_keys, f"{key_name_date}.biprivatekey")
        shutil.copyfile(path_key_public, os.path.join(path_mod, "keys", f"{key_name_date}.bikey"))  # copy to @addon\keys
        print(f" created new key: {path_key_private}")
    return path_key_private


def sign_pbo(path_key_private, path_pbo):
    ret = subprocess.call([path_DSSignFile, path_key_private, path_pbo])
    if (ret != 0): raise Exception(" err sign {ret}")


def sign_folder(path_key_private, path_mod):
    print(f"sign_folder: {path_mod} with {path_key_private}")

    list_pbos = []
    path_addons = os.path.join(path_mod, "addons")
    for file in os.scandir(path_addons):
        if file.path.endswith(".pbo"): list_pbos.append(file)

    count_pbo = 0
    with concurrent.futures.ThreadPoolExecutor(max_workers=32) as executor:
        for file in os.scandir(path_addons):
            if file.path.endswith(".pbo"):
                count_pbo = count_pbo + 1
                executor.submit(sign_pbo, path_key_private, file)
        print(f" started signing {count_pbo} pbos")
    print(f" finished")


def main(argv):
    print(f"--- Start --")

    os.chdir(path_private_keys)

    parser = argparse.ArgumentParser(prog="Signer")

    parser.add_argument("target_folder", type=ascii)
    parser.add_argument("-r", "--reuse_key", action="store_true")
    parser.add_argument("-p", "--primary", action="store_true")

    args = parser.parse_args()

    path_mods = path_mods_primary if args.primary else path_mods_staging

    mod_folder_name = args.target_folder.strip('\"\'')
    mod_path = os.path.join(path_mods, mod_folder_name)
    if not os.path.isdir(mod_path): raise Exception(f"bad mod folder {mod_folder_name}")
    if not os.path.isdir(os.path.join(mod_path, "addons")): raise Exception(f"mod missing addons")
    if not os.path.isdir(os.path.join(mod_path, "keys")): raise Exception(f"mod missing keys")

    mod_short_name = mod_folder_name[1:].lower()
    if (mod_short_name == "bourbonmaprotation"): mod_short_name = "Maps"
    elif (mod_short_name == "zeus-ai"): mod_short_name = "AI"
    elif (mod_short_name == "miscmods"): mod_short_name = "Misc"
    elif (mod_short_name == "hlcmods"): mod_short_name = "HLC"
    elif (mod_short_name == "podagorsk"): mod_short_name = "POD"
    elif (mod_short_name == "torabora"): mod_short_name = "TB"
    else: mod_short_name = mod_short_name[0:4].upper()
    key_name_base = f"{key_prefix}-{mod_short_name}"

    print(f"Mod Folder: {mod_folder_name}")
    print(f"Key Name:   {key_name_base}")
    print(f"Reuse Key:  {args.reuse_key}")

    cleanup(mod_path, key_name_base, args.reuse_key)
    private_key = get_key(mod_path, key_name_base, args.reuse_key)
    sign_folder(private_key, mod_path)

    print("--- End --")
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))
