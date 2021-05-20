import os
import sys
import subprocess

addon_base_path = os.path.dirname(os.getcwd())
    
def cleanup():
    count = 0
    for root, _dirs, files in os.walk(os.path.join(addon_base_path, "addons")):
        for file in files:
            if file.endswith(".sqfc"):
                os.remove(os.path.join(root, file))
                count += 1
    print("cleaned [{} sqfc files]".format(count))

def build():
    compiler_exe = os.path.join(addon_base_path, "ArmaScriptxCompiler.exe")
    if not os.path.isfile(compiler_exe):
        print("Error: ArmaScriptCompiler.exe not found in base folder [{}]".format(compiler_exe))
        raise FileNotFoundError("ArmaScriptCompiler not found")
    ret = subprocess.call([compiler_exe], cwd=addon_base_path)
    print("compiled [ret {}]".format(ret))


def main(argv):
    if (("cleanup" in argv) or (len(argv) < 2)):
        cleanup()
    if (("build" in argv) or (len(argv) < 2)):
        build()

if __name__ == "__main__":
    sys.exit(main(sys.argv))
