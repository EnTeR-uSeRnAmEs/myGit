#include <iostream>
#include "Vector.h"
#include "String.h"
using namespace std;

void testxg()
{
	base<int> *v_b = new Vector<int>;
	delete v_b;
}

void teststr()
{
	base<char> *str_b = new String;
	delete str_b;
}

void test02()
{
	cout << "------------- 以下是Vector的联合测试 -------------" << endl;
	cout << "1. 析构函数测试" << endl;
	cout << "  在函数testxg()中创建base指针指向Vector对象，并删除该指针，输出为：";
	testxg();
	cout << "\n\n";
	cout << "2. fitmem()测试" << endl;
	base<int> *vi1 = new Vector<int>;
	cout << "  base<int> *vi1 = new Vector<int>   vi1的长度为: " << vi1->getlength() << " , vi1的容量为: " << vi1->getcapacity() << endl;
	vi1->fitmem();
	cout << "  进行扩容  vi1->fitmem()            vi1的长度为: " << vi1->getlength() << " , vi1的容量为: " << vi1->getcapacity() << endl;
	cout << endl;
	cout << "3.\"[]\"重载" << endl;
	cout << "  访问 vi1[0]：    ";
	try
	{
		vi1->operator[](0);
	}
	catch (ERROR &e)
	{
		e.print();
		cout << endl;
	}
	cout << "  访问 vi1[-10]：  ";
	try
	{
		vi1->operator[](-10);
	}
	catch (ERROR &e)
	{
		e.print();
		cout << endl;
	}
	cout << endl;
	cout << "4. getlength()和 getcapacity()测试" << endl;
	cout << "  vi1的长度为: " << vi1->getlength() << ", vi1的容量为 : " << vi1->getcapacity() << endl;
	cout << endl;
	cout << "5. empty()测试" << endl;
	cout << "  vi1->empty()   输出为：" << vi1->empty() << endl;
}
void test03()
{
	cout << "------------- 以下是String的联合测试 -------------" << endl;
	cout << "1. 析构函数测试" << endl;
	cout << "  在函数teststr()中创建base指针指向String对象，并删除该指针，输出为：";
	teststr();
	cout << "\n\n";
	cout << "2. fitmem()测试" << endl;
	base<char> *str = new String;
	cout << "  base<char> *str = new String;   str的长度为: " << str->getlength() << " , str的容量为: " << str->getcapacity() << endl;
	str->fitmem();
	cout << "  进行扩容  str->fitmem()            str的长度为: " << str->getlength() << " , str的容量为: " << str->getcapacity() << endl;
	cout << endl;
	cout << "3.\"[]\"重载" << endl;
	cout << "  访问 str[0]：    ";
	try
	{
		str->operator[](-10);
	}
	catch (ERROR &e)
	{
		e.print();
		cout << endl;
	}
	cout << "  访问 str[-10]：  ";
	try
	{
		str->operator[](-10);
	}
	catch (ERROR &e)
	{
		e.print();
		cout << endl;
	}
	cout << endl;
	cout << "4. getlength()和 getcapacity()测试" << endl;
	cout << "  str的长度为: " << str->getlength() << ", str的容量为 : " << str->getcapacity() << endl;
	cout << endl;
	cout << "5. empty()测试" << endl;
	cout << "  str->empty()   输出为：" << str->empty() << endl;
}
int main()
{
	test02();
	test03();
	system("pause");
	return 0;
}