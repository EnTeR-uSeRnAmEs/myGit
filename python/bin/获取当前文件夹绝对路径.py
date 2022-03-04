import os,sys

def cd2curdir():
    try:
        import os
    except ImportError:
        pass
    os.chdir(os.path.split(os.path.realpath(os.path.dirname(sys.argv[0]))))



if __name__ == '__main__':
    print(os.getcwd())
    cd2curdir()
    print(os.getcwd())
