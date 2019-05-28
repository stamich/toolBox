import sys, os


def main(argv):
    fileCreator()


def fileCreator():
    f = open(".gitignore", "w+")
    for i in range(1):
        f.write("cmake-build-debug/**\n")
        f.write(".idea/**\n")
        f.write("\n")
        f.write("*.iml")
    f.close()

    # f = open(".gitattributes", "w+")
    # for i in range(1):
    #     f.write("###############################################################################\n")
    #     f.write("# Set default behavior to automatically normalize line endings.\n")
    #     f.write("###############################################################################\n")
    #     f.write("* text=auto\n")
    #     f.write("\n")
    #     f.write("###############################################################################\n")
    #     f.write("# Set default behavior for command prompt diff.\n")
    #     f.write("\n")
    #     f.write("# This is need for earlier builds of msysgit that does not have it on by\n")
    #     f.write("# default for csharp files.\n")
    #     f.write("# Note: This is only used by command line\n")
    #     f.write("###############################################################################\n")
    #     f.write("#*.cs     diff=csharp\n")
    #     f.write("\n")
    # f.close()


if __name__ == '__main__':
    main(sys.argv[1:])