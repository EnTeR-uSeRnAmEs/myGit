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
	cout << "------------- ������Vector�����ϲ��� -------------" << endl;
	cout << "1. ������������" << endl;
	cout << "  �ں���testxg()�д���baseָ��ָ��Vector���󣬲�ɾ����ָ�룬���Ϊ��";
	testxg();
	cout << "\n\n";
	cout << "2. fitmem()����" << endl;
	base<int> *vi1 = new Vector<int>;
	cout << "  base<int> *vi1 = new Vector<int>   vi1�ĳ���Ϊ: " << vi1->getlength() << " , vi1������Ϊ: " << vi1->getcapacity() << endl;
	vi1->fitmem();
	cout << "  ��������  vi1->fitmem()            vi1�ĳ���Ϊ: " << vi1->getlength() << " , vi1������Ϊ: " << vi1->getcapacity() << endl;
	cout << endl;
	cout << "3.\"[]\"����" << endl;
	cout << "  ���� vi1[0]��    ";
	try
	{
		vi1->operator[](0);
	}
	catch (ERROR &e)
	{
		e.print();
		cout << endl;
	}
	cout << "  ���� vi1[-10]��  ";
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
	cout << "4. getlength()�� getcapacity()����" << endl;
	cout << "  vi1�ĳ���Ϊ: " << vi1->getlength() << ", vi1������Ϊ : " << vi1->getcapacity() << endl;
	cout << endl;
	cout << "5. empty()����" << endl;
	cout << "  vi1->empty()   ���Ϊ��" << vi1->empty() << endl;
}
void test03()
{
	cout << "------------- ������String�����ϲ��� -------------" << endl;
	cout << "1. ������������" << endl;
	cout << "  �ں���teststr()�д���baseָ��ָ��String���󣬲�ɾ����ָ�룬���Ϊ��";
	teststr();
	cout << "\n\n";
	cout << "2. fitmem()����" << endl;
	base<char> *str = new String;
	cout << "  base<char> *str = new String;   str�ĳ���Ϊ: " << str->getlength() << " , str������Ϊ: " << str->getcapacity() << endl;
	str->fitmem();
	cout << "  ��������  str->fitmem()            str�ĳ���Ϊ: " << str->getlength() << " , str������Ϊ: " << str->getcapacity() << endl;
	cout << endl;
	cout << "3.\"[]\"����" << endl;
	cout << "  ���� str[0]��    ";
	try
	{
		str->operator[](-10);
	}
	catch (ERROR &e)
	{
		e.print();
		cout << endl;
	}
	cout << "  ���� str[-10]��  ";
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
	cout << "4. getlength()�� getcapacity()����" << endl;
	cout << "  str�ĳ���Ϊ: " << str->getlength() << ", str������Ϊ : " << str->getcapacity() << endl;
	cout << endl;
	cout << "5. empty()����" << endl;
	cout << "  str->empty()   ���Ϊ��" << str->empty() << endl;
}
int main()
{
	test02();
	test03();
	system("pause");
	return 0;
}