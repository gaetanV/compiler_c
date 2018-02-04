
import subprocess

subprocess.call("node-gyp rebuild --msvs_version=2015",shell=True)
subprocess.call("node hook.js")