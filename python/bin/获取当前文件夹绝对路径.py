import os

def cd2curdir():
    try:
        import os
    except ImportError:
        pass
    os.chdir(os.path.split(os.path.abspath(__file__))[0])



if __name__ == '__main__':
    print(os.getcwd())
    cd2curdir()
    print(os.getcwd())
