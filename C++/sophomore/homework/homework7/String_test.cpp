#include <bits/stdc++.h>
#include "String.h"
using namespace std;

void test01()
{
	cout << "------------- ���캯���Ĳ��� -------------" << endl;

	cout << "1. String S0\n";
	String S0;
	cout << "   S0�ĳ���Ϊ: " << S0.getlength() << " , S0������Ϊ: " << S0.getcapacity() << endl;
	cout << endl;

	cout << "2. String S1 = \"This is a test.\"\n";
	String S1 = "This is a test.";
	cout << "   S1�ĳ���Ϊ: " << S1.getlength() << " , S1������Ϊ: " << S1.getcapacity() << endl;
	cout << endl;

	cout << "3. String S2 = S1\n";
	String S2 = S1;
	cout << "   S2�ĳ���Ϊ: " << S2.getlength() << " , S2������Ϊ: " << S2.getcapacity() << endl;
	cout << endl;

	cout << "4. String S3('c', 10)\n";
	String S3('c', 10);
	cout << "   S3�ĳ���Ϊ: " << S3.getlength() << " , S3������Ϊ: " << S3.getcapacity() << endl;
	cout << endl;
	cout << "   String temp('c', -1)\n";
	try
	{
		// cout << "   ";
		String temp('c', -1);
	}
	catch (ERROR &e)
	{
		cout << "   ";
		e.print();
		cout << endl;
	}
	cout << endl;

	cout << "5. String S4(S2, 10, 4)\n";
	String S4(S2, 10, 4);
	cout << "   S4�ĳ���Ϊ: " << S4.getlength() << " , S4������Ϊ: " << S4.getcapacity() << endl;
	cout << endl;
	cout << "   String temp(S2, -5, 4)\n";
	try
	{
		String temp(S2, -5, 4);
		cout << "   temp�ĳ���Ϊ: " << temp.getlength() << " , temp������Ϊ: " << temp.getcapacity() << endl;
		// cout << "   ";
	}
	catch (ERROR &e)
	{
		cout << "   ";
		e.print();
		cout << endl;
	}
	cout << endl;
	cout << "   String temp(S2, 10, -1)\n";
	try
	{
		// cout << "   ";
		String temp(S2, 10, -1);
	}
	catch (ERROR &e)
	{
		cout << "   ";
		e.print();
		cout << endl;
	}
	cout << endl;

	cout << "6. String S5(\"This is a test.\", 10)\n";
	// cout << "   ";
	String S5("This is a test.", 10);
	cout << "   S5�ĳ���Ϊ: " << S5.getlength() << " , S5������Ϊ: " << S5.getcapacity() << endl;
	cout << endl;
	cout << "   String temp(\"This is a test.\", -5)\n";
	try
	{
		// cout << "   ";
		String temp("This is a test.", -5);
		cout << "   temp�ĳ���Ϊ: " << temp.getlength() << " , temp������Ϊ: " << temp.getcapacity() << endl;
		// cout << "   ";
	}
	catch (ERROR &e)
	{
		cout << "   ";
		e.print();
		cout << endl;
	}
	cout << endl;
	cout << "------------- ��������صĲ��� -------------" << endl;
	cout << "1.\"<<\" �� \">>\" ����" << endl;
	cout << "  ���������ַ�����S0(cin >> S0)   ";
	// cout << endl;
	// cout << "   ";
	cin >> S0;
	cout << "  S0�����: " << S0 << "  S0�ĳ���Ϊ: " << S0.getlength() << " ,S0������Ϊ : " << S0.getcapacity() << endl;
	cout << endl;
	cout << "2.\"+\" , \"+=\" �� \"=\" ����" << endl;
	cout << "  (1)�ֱ��� asdfg �� hjkl; ����S1��S2" << endl;
	S1 = "asdfg";
	S2 = "hjkl;";
	cout << "     S1 + S2            ���Ϊ:  " << S1 + S2 << endl;
	cout << "     ��S1��S1 + S2�ֱ�ֵ��S3" << endl;
	S3 = S1;
	cout << "     S3 = S1            ���Ϊ:  " << S3 << endl;
	S3 = S1 + S2;
	cout << "     S3 = S1 + S2       ���Ϊ:  " << S3 << endl;
	S4 = "test";
	cout << "     S4 = \"test\"        ���Ϊ:  " << S4 << endl;
	cout << "     S4 + \" Hello!\"       ���Ϊ:  " << S4 + " Hello!" << endl;
	cout << "     \"Hello! \" + S4       ���Ϊ:  "
		 << "Hello! " + S4 << endl;
	cout << "     S4 + 'C'           ���Ϊ:  " << S4 + 'C' << endl;
	cout << "     'C' + S4           ���Ϊ:  " << 'C' + S4 << endl;
	S3 += S1 += S2;
	cout << "\n  (2)S3 += S1 += S2   ���Ϊ:   S3 " << S4 << endl;
	cout << "                                S1 " << S1 << endl;
	cout << "\n3.�߼������\"==\", \"!=\", \">\", \">=\", \"<\", \"<=\",  ����" << endl;
	cout << "  ��S1��S4��S5���Ƚ�, ����S4, S5��\"test\"��ʼ��:" << endl;
	S4 = S5 = "test";
	cout << "  S1 = " << S1 << endl;
	cout << "  S4 = " << S4 << endl;
	cout << "  S5 = " << S5 << endl;
	cout << "  (1)S4 == S5 ?      ���Ϊ:  " << (S4 == S5) << endl;
	cout << "     S5 == S4 ?      ���Ϊ:  " << (S5 == S4) << endl;
	cout << "     S4 == S4 ?      ���Ϊ:  " << (S4 == S4) << endl;
	cout << "     S1 == S5 ?      ���Ϊ:  " << (S1 == S5) << endl;
	cout << "     S4 == \"test\" ?  ���Ϊ:  " << (S4 == "test") << endl;
	cout << "     \"test\" == S1 ?  ���Ϊ:  " << ("test" == S1) << endl;
	cout << endl;
	cout << "  (2)S4 != S5 ?      ���Ϊ:  " << (S4 != S5) << endl;
	cout << "     S5 != S4 ?      ���Ϊ:  " << (S5 != S4) << endl;
	cout << "     S4 != S4 ?      ���Ϊ:  " << (S4 != S4) << endl;
	cout << "     S1 != S5 ?      ���Ϊ:  " << (S1 != S5) << endl;
	cout << "     S4 != \"test\" ?  ���Ϊ:  " << (S4 != "test") << endl;
	cout << "     \"test\" != S1 ?  ���Ϊ:  " << ("test" != S1) << endl;
	cout << endl;
	cout << "  (3)S4 > S5 ?       ���Ϊ:  " << (S4 > S5) << endl;
	cout << "     S5 > S4 ?       ���Ϊ:  " << (S5 > S4) << endl;
	cout << "     S4 > S4 ?       ���Ϊ:  " << (S4 > S4) << endl;
	cout << "     S1 > S5 ?       ���Ϊ:  " << (S1 > S5) << endl;
	cout << "     S4 > \"test\" ?   ���Ϊ:  " << (S4 > "test") << endl;
	cout << "     \"test\" > S1 ?   ���Ϊ:  " << ("test" > S1) << endl;
	cout << endl;
	cout << "  (4)S4 >= S5 ?      ���Ϊ:  " << (S4 >= S5) << endl;
	cout << "     S5 >= S4 ?      ���Ϊ:  " << (S5 >= S4) << endl;
	cout << "     S4 >= S4 ?      ���Ϊ:  " << (S4 >= S4) << endl;
	cout << "     S1 >= S5 ?      ���Ϊ:  " << (S1 >= S5) << endl;
	cout << "     S4 >= \"test\" ?  ���Ϊ:  " << (S4 >= "test") << endl;
	cout << "     \"test\" >= S1 ?  ���Ϊ:  " << ("test" >= S1) << endl;
	cout << endl;
	cout << "  (5)S4 < S5 ?       ���Ϊ:  " << (S4 < S5) << endl;
	cout << "     S5 < S4 ?       ���Ϊ:  " << (S5 < S4) << endl;
	cout << "     S4 < S4 ?       ���Ϊ:  " << (S4 < S4) << endl;
	cout << "     S1 < S5 ?       ���Ϊ:  " << (S1 < S5) << endl;
	cout << "     S4 < \"test\" ?   ���Ϊ:  " << (S4 < "test") << endl;
	cout << "     \"test\" < S1 ?   ���Ϊ:  " << ("test" < S1) << endl;
	cout << endl;
	cout << "  (6)S4 <= S5 ?      ���Ϊ:  " << (S4 <= S5) << endl;
	cout << "     S5 <= S4 ?      ���Ϊ:  " << (S5 <= S4) << endl;
	cout << "     S4 <= S4 ?      ���Ϊ:  " << (S4 <= S4) << endl;
	cout << "     S1 <= S5 ?      ���Ϊ:  " << (S1 <= S5) << endl;
	cout << "     S4 <= \"test\" ?  ���Ϊ:  " << (S4 <= "test") << endl;
	cout << "     \"test\" <= S1 ?  ���Ϊ:  " << ("test" <= S1) << endl;
	cout << endl;
	cout << "\n4.\"[]\" ����" << endl;
	cout << "  (1)S0 = \"0123456789\"������9��0���:  ";
	S0 = "0123456789";
	for (int i = 9; i > -1; i--)
	{
		if (i != 0)
		{
			cout << S0[i] << " ";
		}
		else
			cout << S0[i] << endl;
	}
	cout << endl;
	S0[0] = 'c';
	cout << "  (2)S0[0] = 'c'      ���Ϊ:  " << S0 << endl;
	S0[-1] = S0[0];
	cout << "     S0[-1] = S0[0]   ���Ϊ:  " << S0 << endl;
	cout << "     S0[10]           ���Ϊ:  ";
	try
	{
		S0[10];
	}
	catch (ERROR &e)
	{
		// cout << "   ";
		e.print();
		cout << endl;
	}
	S0 = "";

	cout << "\n------------- ��Ա�����Ĳ��� -------------" << endl;
	S0 = "";
	cout << "  S0 = \"\"" << endl;
	S2 = "This is a test.";
	cout << "  S2 = \"This is a test.\"" << endl;
	cout << "  S4 = \"test\"" << endl;
	cout << endl;
	cout << "1.empyt()����" << endl;
	cout << "  S0.empty()        ���Ϊ:    " << S0.empty() << endl;
	cout << "  S4.empty()        ���Ϊ:    " << S4.empty() << endl;
	cout << endl;
	cout << "2.getlength()����" << endl;
	cout << "  S0.getlength()       ���Ϊ:    " << S0.getlength() << endl;
	cout << "  S4.getlength()       ���Ϊ:    " << S4.getlength() << endl;
	cout << endl;
	cout << "3.getcapacity()����" << endl;
	cout << "  S0.getcapacity()     ���Ϊ:    " << S0.getcapacity() << endl;
	cout << "  S4.getcapacity()     ���Ϊ:    " << S4.getcapacity() << endl;
	cout << endl;
	cout << "4.substr()����" << endl;
	cout << "  S0.substr(0)      ���Ϊ:    " << S0.substr(0) << endl;
	cout << "  S2.substr(5)      ���Ϊ:    " << S2.substr(5) << endl;
	cout << "  S2.substr(10, 4)  ���Ϊ:    " << S2.substr(10, 4) << endl;
	cout << "  S2.substr(-5, 4)  ���Ϊ:    " << S2.substr(-5, 4) << endl;
	try
	{
		cout << "  S2.substr(100, 4) ���Ϊ:    " << S2.substr(100, 4) << endl;
	}
	catch (ERROR &e)
	{
		e.print();
		cout << endl;
	}
	try
	{
		cout << "  S2.substr(10, -4) ���Ϊ:    " << S2.substr(10, -4) << endl;
	}
	catch (ERROR &e)
	{
		e.print();
		cout << endl;
	}
	cout << "  S0 = " << S0 << endl;
	cout << "  S2 = " << S2 << endl;
	cout << endl;
	cout << "5.c_str()����" << endl;
	cout << "  S0.c_str()        ���Ϊ:    ";
	printf("%p\n", S0.c_str());
	cout << "  S2.c_str()        ���Ϊ:    ";
	printf("%p\n", S2.c_str());
	cout << endl;
	cout << "6.insert()����" << endl;
	cout << "  S0.insert(0, \"Hello world!\")" << endl
		 << "                    ���Ϊ:    " << S0.insert(0, "Hello world!") << endl;
	cout << "  S2.insert(10, \"Hello world!\")" << endl
		 << "                    ���Ϊ:    " << S2.insert(10, "Hello world!") << endl;
	try
	{
		cout << "  S0.insert(6, S0)���Ϊ:    " << S0.insert(6, S0) << endl;
	}
	catch (ERROR &e)
	{
		e.print();
		cout << endl;
	}
	try
	{
		cout << "  S2.insert(100, S0)  ���Ϊ:    " << S2.insert(100, S0) << endl;
	}
	catch (ERROR &e)
	{
		e.print();
		cout << endl;
	}
	cout << endl;
	cout << "  S0 = " << S0 << endl;
	cout << "  S2 = " << S2 << endl;
	cout << endl;
	S0 = "";
	S2 = "This is a test.";
	cout << "  ====����S0, S2====" << endl;
	cout << "  S0 = \"\"" << endl
		 << "  S2 = \"This is a test.\"" << endl;
	cout << endl;
	cout << "7.find()����" << endl;
	cout << "  S2.find(S4)       ���Ϊ:    " << S2.find(S4) << endl;
	cout << "  S4.find(S2)       ���Ϊ:    " << S4.find(S2) << endl;
	cout << "  S4.find(S0)       ���Ϊ:    " << S4.find(S0) << endl;
	cout << "  S2.find(\"test\")   ���Ϊ:    " << S2.find("test") << endl;
	cout << "  S2.find('t')      ���Ϊ:    " << S2.find('t') << endl;
	cout << endl;
	cout << "8.erase()����" << endl;
	cout << "  S2.erase(10, 4)   ���Ϊ:    " << S2.erase(10, 4) << endl;
	cout << "  S2.erase(4)       ���Ϊ:    " << S2.erase(4) << endl;
	try
	{
		cout << "  S2.erase(100)     ���Ϊ:    " << S2.erase(100) << endl;
	}
	catch (ERROR &e)
	{
		e.print();
		cout << endl;
	}
	try
	{
		cout << "  S2.erase(0, -1)   ���Ϊ:    " << S2.erase(0, -1) << endl;
	}
	catch (ERROR &e)
	{
		e.print();
		cout << endl;
	}
	cout << endl;
	cout << "  S2 = " << S2 << endl;
	cout << endl;
	S2 = "This is a test.";
	cout << "  ======����S2======" << endl;
	cout << "  S2 = \"This is a test.\"" << endl;
	cout << endl;
	cout << "9.replace()����" << endl;
	cout << "  S2.replace(0, 4, S4)" << endl
		 << "                    ���Ϊ:    " << S2.replace(0, 4, S4) << endl;
	try
	{
		cout << "  S2.replace(10, 100, \"Hello world!\")" << endl
			 << "                    ���Ϊ:    " << S2.replace(10, 100, "Hello world!") << endl;
	}
	catch (ERROR &e)
	{
		e.print();
		cout << endl;
	}
	cout << endl;
	cout << "  S2 = " << S2 << endl;
	cout << endl;
	S2 = "This is a test.";
	cout << "  ======����S2======" << endl;
	cout << "  S2 = \"This is a test.\"" << endl;
	cout << endl;
	cout << "10.trim()����" << endl;
	S0 = "  test  ";
	S2 = "        This is a test.";
	cout << "  S0 = \"  test  \"" << endl
		 << "  S2 = \"        This is a test.\"" << endl;
	cout << endl;
	cout << "  S2.trim()         ���Ϊ:    " << S2.trim() << endl;
	cout << "  S4.trim()         ���Ϊ:    " << S4.trim() << endl;
	cout << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}