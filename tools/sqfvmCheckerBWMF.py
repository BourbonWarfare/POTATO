import os
import sys
import subprocess
import concurrent.futures

path_root = os.path.realpath(os.path.dirname(os.path.dirname(__file__)))
sqfvm_exe = os.path.join(path_root, "sqfvm.exe")
path_bwmf = os.path.join(os.path.dirname(path_root), "bwmf")
virtual_paths = ["{}|/".format(path_bwmf),]
print(f"Checking bwmf @ {path_bwmf}")
if not os.path.isdir(os.path.join(path_bwmf, "loadouts")):
    raise
print(f"Checking sqfvm_exe @ {sqfvm_exe}")
if not os.path.isfile(sqfvm_exe):
    print("Error: sqfvm.exe not found in base folder [{}]".format(sqfvm_exe))
    raise


def process_file(filePath, skipA3Warnings=True):
    with open(filePath, "r", encoding="utf-8", errors="ignore") as file:
        content = file.read()
        if content.startswith("//pragma SKIP_COMPILE"):
            return False
    cmd = [sqfvm_exe, "--input", filePath, "--parse-only", "--automated"]
    for v in virtual_paths:
        cmd.append("-v")
        cmd.append(v)
    # cmd.append("-V")
    proc = subprocess.Popen(cmd, stdout=subprocess.PIPE, universal_newlines=True)
    try:
        ret = proc.wait(600)  # max wait - seconds
    except Exception as _e:
        print("sqfvm timed out: {}".format(filePath))
        return True
    # print("{} = {}".format(filePath, ret))

    fileHasError = False
    keepReadingLines = True
    while keepReadingLines:
        line = proc.stdout.readline()
        if not line:
            keepReadingLines = False
        else:
            line = line.rstrip()
            print("  {}".format(line))
            # if line.startswith("[ERR]"):
            #     fileHasError = True
            # if not (
            #     skipA3Warnings
            #     and line.startswith("[WRN]")
            #     and ("a3/" in line)
            #     and (("Unexpected IFDEF" in line) or ("defined twice" in line))
            # ):
            #     print("  {}".format(line))
    return fileHasError


def main():

    error_count = 0
    arma_files = [os.path.join(path_bwmf, "description.ext")]
    print("Checking {} files".format(len(arma_files)))
    with concurrent.futures.ThreadPoolExecutor(max_workers=12) as executor:
        for fileError in executor.map(process_file, arma_files):
            if fileError:
                error_count += 1

    print("Errors: {}".format(error_count))
    return error_count


if __name__ == "__main__":
    sys.exit(main())
