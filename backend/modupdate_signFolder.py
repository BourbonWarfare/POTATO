# PabstMirror - Automate signing mod folders with bisign - https://github.com/BrettMayson/bisign
# Usage `py ./modupdate_signFolder.py "@miscmods"`  (note: quotes on folder because @symbol causes problems)

import os
import sys
import subprocess
import datetime
import shutil
import concurrent.futures
from itertools import repeat

key_prefix = "BW"

path_start = os.getcwd()
path_bisign = os.path.join(path_start, "bisign.exe")
path_private_keys = os.path.join(path_start, "private_keys")
path_base_arma = "E:\\BourbonWarfare\\ArmaMods\\primary_staging"


def sign_pbo(path_key_private, path_pbo):
    ret = subprocess.call([path_bisign, "sign", path_key_private, path_pbo])
    if (ret != 0): raise Exception("err sign {}".format(ret))
    return "- signed: {}".format(os.path.basename(path_pbo))


def sign_folder(path_mod, key_name, path_key_private):
    print("sign_folder: {}".format(path_mod))

    if (path_key_private != ""):
        print("- using existing key {}".format(path_key_private))
    else:
        for file in os.listdir(path_private_keys):
            if file.startswith(key_name): os.remove(os.path.join(path_private_keys, file))

        # Generate new private key
        key_name = "{}-{}".format(key_name, datetime.datetime.today().strftime("%y%m%d"))
        ret = subprocess.call([path_bisign, "keygen", key_name])
        if (ret != 0): raise Exception("err keygen {}".format(ret))
        path_key_public = os.path.join(path_private_keys, "{}.bikey".format(key_name))
        path_key_private = os.path.join(path_private_keys, "{}.biprivatekey".format(key_name))

        # Cleanup addon's keys folder and copy public into it
        path_addon_keys = os.path.join(path_mod, "keys")
        if not os.path.exists(path_addon_keys): os.makedirs(path_addon_keys)
        for file in os.listdir(path_addon_keys): os.remove(os.path.join(path_addon_keys, file))
        shutil.copy(path_key_public, path_addon_keys)

        print("- created new key {}".format(path_key_private))

    list_pbos = []
    print("\nRemoving: ")
    for root, _dirs, files in os.walk(path_mod):
        for file in files:
            path_file = os.path.join(root, file)
            if file.endswith(".bisign") and (".pbo.{}-".format(key_prefix)) in file:
                print(" {},".format(file), end='')
                os.remove(path_file)
            if file.endswith(".pbo"): list_pbos.append(path_file)
            
    print("\n\nSigning {} pbos".format(len(list_pbos)))
    with concurrent.futures.ThreadPoolExecutor(max_workers=12) as executor:
        for ret_t in executor.map(sign_pbo, repeat(path_key_private), list_pbos):
            print(ret_t)


def main(argv):
    print("\n\n--- Start -- {}".format(argv))
    if not os.path.isfile(path_bisign): raise Exception("missing bisign.exe - {}".format(path_bisign))
    if not os.path.isdir(path_private_keys): raise Exception("missing keys dir - {}".format(path_private_keys))
    if not os.path.isdir(path_base_arma): raise Exception("missing mods dir - {}".format(path_base_arma))

    os.chdir(path_private_keys)

    # ARG 1 - Addon folder name
    if (len(argv) < 2): raise Exception("need folder name as arg")
    arg_mod = argv[1]
    path_mod = os.path.join(path_base_arma, arg_mod)
    if not os.path.isdir(path_mod): raise Exception("bad mod folder name {}".format(arg_mod))

    path_key_private = ""
    addon_clean_name = (os.path.basename(path_mod))[1:]  # strip "@"
    key_name = "{}-{}".format(key_prefix, addon_clean_name)

    # ARG 2 (OPTIONAL) - use existing key
    if (len(argv) > 2) and ("1" == argv[2]):
        # try to use existing key if it exists (delete to gen new)
        for file in os.listdir(path_private_keys):
            if file.startswith(key_name) and file.endswith(".biprivatekey"):
                path_key_private = os.path.join(path_private_keys, file)

    sign_folder(path_mod, key_name, path_key_private)

    print("Done".format(argv))
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))
