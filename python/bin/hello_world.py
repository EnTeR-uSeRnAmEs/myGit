code='''\
def f(x):
	return x**2
def g(a,b):
	return f(a)+f(b)
a=2
b=3
print(g(a,b))'''


def reterminal(code):	
	import sys
	filepath = "C:\\Users\\24798\\Desktop"
	filename = "py_terminal.txt"
	fullname = filepath + "\\" +filename
	standard_output = sys.stdout
	sys.stdout = open(fullname, "w+")
	#切换到txt
	exec(code,globals())
	#退出txt终端
	sys.stdout = standard_output
	return open(fullname, "r").read()

print(reterminal(code))
