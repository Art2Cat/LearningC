#!/usr/bin/env python3

import os


def remove_file(path):
    if os.path.isfile(path):
        os.remove(path)
        print("removed: %s" % path)
    else:  # Show an error ##
        print("Error: %s file not found" % path)


def explore(dir_path):
    for root, _, files in os.walk(dir_path):
        files[:] = [f for f in files if '.exe' in f or '.c.o' in f
                    or '.' not in f or '.out' in f]
        for file in files:
            path = os.path.join(root, os.path.basename(file))
            if '.git' not in path:
                remove_file(path)


def main(dir):
    if os.path.isfile(dir):
        # remove_file(dir)
        pass
    elif os.path.isdir(dir):
        explore(dir)


if __name__ == "__main__":
    dir = os.path.abspath(".")
    print(dir)
    main(dir)
    print("pass")
