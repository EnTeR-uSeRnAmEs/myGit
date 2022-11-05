#include <bits/stdc++.h>
#include "String.h"
using namespace std;

void test01()
{
	cout << "------------- 构造函数的测试 -------------" << endl;

	cout << "1. String S0\n";
	String S0;
	cout << "   S0的长度为: " << S0.getlength() << " , S0的容量为: " << S0.getcapacity() << endl;
	cout << endl;

	cout << "2. String S1 = \"This is a test.\"\n";
	String S1 = "This is a test.";
	cout << "   S1的长度为: " << S1.getlength() << " , S1的容量为: " << S1.getcapacity() << endl;
	cout << endl;

	cout << "3. String S2 = S1\n";
	String S2 = S1;
	cout << "   S2的长度为: " << S2.getlength() << " , S2的容量为: " << S2.getcapacity() << endl;
	cout << endl;

	cout << "4. String S3('c', 10)\n";
	String S3('c', 10);
	cout << "   S3的长度为: " << S3.getlength() << " , S3的容量为: " << S3.getcapacity() << endl;
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
	cout << "   S4的长度为: " << S4.getlength() << " , S4的容量为: " << S4.getcapacity() << endl;
	cout << endl;
	cout << "   String temp(S2, -5, 4)\n";
	try
	{
		String temp(S2, -5, 4);
		cout << "   temp的长度为: " << temp.getlength() << " , temp的容量为: " << temp.getcapacity() << endl;
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
	cout << "   S5的长度为: " << S5.getlength() << " , S5的容量为: " << S5.getcapacity() << endl;
	cout << endl;
	cout << "   String temp(\"This is a test.\", -5)\n";
	try
	{
		// cout << "   ";
		String temp("This is a test.", -5);
		cout << "   temp的长度为: " << temp.getlength() << " , temp的容量为: " << temp.getcapacity() << endl;
		// cout << "   ";
	}
	catch (ERROR &e)
	{
		cout << "   ";
		e.print();
		cout << endl;
	}
	cout << endl;
	cout << "------------- 运算符重载的测试 -------------" << endl;
	cout << "1.\"<<\" 和 \">>\" 重载" << endl;
	cout << "  输入任意字符串到S0(cin >> S0)   ";
	// cout << endl;
	// cout << "   ";
	cin >> S0;
	cout << "  S0的输出: " << S0 << "  S0的长度为: " << S0.getlength() << " ,S0的容量为 : " << S0.getcapacity() << endl;
	cout << endl;
	cout << "2.\"+\" , \"+=\" 和 \"=\" 重载" << endl;
	cout << "  (1)分别用 asdfg 和 hjkl; 创建S1和S2" << endl;
	S1 = "asdfg";
	S2 = "hjkl;";
	cout << "     S1 + S2            输出为:  " << S1 + S2 << endl;
	cout << "     将S1与S1 + S2分别赋值给S3" << endl;
	S3 = S1;
	cout << "     S3 = S1            输出为:  " << S3 << endl;
	S3 = S1 + S2;
	cout << "     S3 = S1 + S2       输出为:  " << S3 << endl;
	S4 = "test";
	cout << "     S4 = \"test\"        输出为:  " << S4 << endl;
	cout << "     S4 + \" Hello!\"       输出为:  " << S4 + " Hello!" << endl;
	cout << "     \"Hello! \" + S4       输出为:  "
		 << "Hello! " + S4 << endl;
	cout << "     S4 + 'C'           输出为:  " << S4 + 'C' << endl;
	cout << "     'C' + S4           输出为:  " << 'C' + S4 << endl;
	S3 += S1 += S2;
	cout << "\n  (2)S3 += S1 += S2   输出为:   S3 " << S4 << endl;
	cout << "                                S1 " << S1 << endl;
	cout << "\n3.逻辑运算符\"==\", \"!=\", \">\", \">=\", \"<\", \"<=\",  重载" << endl;
	cout << "  将S1、S4、S5作比较, 其中S4, S5用\"test\"初始化:" << endl;
	S4 = S5 = "test";
	cout << "  S1 = " << S1 << endl;
	cout << "  S4 = " << S4 << endl;
	cout << "  S5 = " << S5 << endl;
	cout << "  (1)S4 == S5 ?      结果为:  " << (S4 == S5) << endl;
	cout << "     S5 == S4 ?      结果为:  " << (S5 == S4) << endl;
	cout << "     S4 == S4 ?      结果为:  " << (S4 == S4) << endl;
	cout << "     S1 == S5 ?      结果为:  " << (S1 == S5) << endl;
	cout << "     S4 == \"test\" ?  结果为:  " << (S4 == "test") << endl;
	cout << "     \"test\" == S1 ?  结果为:  " << ("test" == S1) << endl;
	cout << endl;
	cout << "  (2)S4 != S5 ?      结果为:  " << (S4 != S5) << endl;
	cout << "     S5 != S4 ?      结果为:  " << (S5 != S4) << endl;
	cout << "     S4 != S4 ?      结果为:  " << (S4 != S4) << endl;
	cout << "     S1 != S5 ?      结果为:  " << (S1 != S5) << endl;
	cout << "     S4 != \"test\" ?  结果为:  " << (S4 != "test") << endl;
	cout << "     \"test\" != S1 ?  结果为:  " << ("test" != S1) << endl;
	cout << endl;
	cout << "  (3)S4 > S5 ?       结果为:  " << (S4 > S5) << endl;
	cout << "     S5 > S4 ?       结果为:  " << (S5 > S4) << endl;
	cout << "     S4 > S4 ?       结果为:  " << (S4 > S4) << endl;
	cout << "     S1 > S5 ?       结果为:  " << (S1 > S5) << endl;
	cout << "     S4 > \"test\" ?   结果为:  " << (S4 > "test") << endl;
	cout << "     \"test\" > S1 ?   结果为:  " << ("test" > S1) << endl;
	cout << endl;
	cout << "  (4)S4 >= S5 ?      结果为:  " << (S4 >= S5) << endl;
	cout << "     S5 >= S4 ?      结果为:  " << (S5 >= S4) << endl;
	cout << "     S4 >= S4 ?      结果为:  " << (S4 >= S4) << endl;
	cout << "     S1 >= S5 ?      结果为:  " << (S1 >= S5) << endl;
	cout << "     S4 >= \"test\" ?  结果为:  " << (S4 >= "test") << endl;
	cout << "     \"test\" >= S1 ?  结果为:  " << ("test" >= S1) << endl;
	cout << endl;
	cout << "  (5)S4 < S5 ?       结果为:  " << (S4 < S5) << endl;
	cout << "     S5 < S4 ?       结果为:  " << (S5 < S4) << endl;
	cout << "     S4 < S4 ?       结果为:  " << (S4 < S4) << endl;
	cout << "     S1 < S5 ?       结果为:  " << (S1 < S5) << endl;
	cout << "     S4 < \"test\" ?   结果为:  " << (S4 < "test") << endl;
	cout << "     \"test\" < S1 ?   结果为:  " << ("test" < S1) << endl;
	cout << endl;
	cout << "  (6)S4 <= S5 ?      结果为:  " << (S4 <= S5) << endl;
	cout << "     S5 <= S4 ?      结果为:  " << (S5 <= S4) << endl;
	cout << "     S4 <= S4 ?      结果为:  " << (S4 <= S4) << endl;
	cout << "     S1 <= S5 ?      结果为:  " << (S1 <= S5) << endl;
	cout << "     S4 <= \"test\" ?  结果为:  " << (S4 <= "test") << endl;
	cout << "     \"test\" <= S1 ?  结果为:  " << ("test" <= S1) << endl;
	cout << endl;
	cout << "\n4.\"[]\" 重载" << endl;
	cout << "  (1)S0 = \"0123456789\"索引从9到0输出:  ";
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
	cout << "  (2)S0[0] = 'c'      输出为:  " << S0 << endl;
	S0[-1] = S0[0];
	cout << "     S0[-1] = S0[0]   输出为:  " << S0 << endl;
	cout << "     S0[10]           输出为:  ";
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

	cout << "\n------------- 成员函数的测试 -------------" << endl;
	S0 = "";
	cout << "  S0 = \"\"" << endl;
	S2 = "This is a test.";
	cout << "  S2 = \"This is a test.\"" << endl;
	cout << "  S4 = \"test\"" << endl;
	cout << endl;
	cout << "1.empyt()测试" << endl;
	cout << "  S0.empty()        输出为:    " << S0.empty() << endl;
	cout << "  S4.empty()        输出为:    " << S4.empty() << endl;
	cout << endl;
	cout << "2.getlength()测试" << endl;
	cout << "  S0.getlength()       输出为:    " << S0.getlength() << endl;
	cout << "  S4.getlength()       输出为:    " << S4.getlength() << endl;
	cout << endl;
	cout << "3.getcapacity()测试" << endl;
	cout << "  S0.getcapacity()     输出为:    " << S0.getcapacity() << endl;
	cout << "  S4.getcapacity()     输出为:    " << S4.getcapacity() << endl;
	cout << endl;
	cout << "4.substr()测试" << endl;
	cout << "  S0.substr(0)      输出为:    " << S0.substr(0) << endl;
	cout << "  S2.substr(5)      输出为:    " << S2.substr(5) << endl;
	cout << "  S2.substr(10, 4)  输出为:    " << S2.substr(10, 4) << endl;
	cout << "  S2.substr(-5, 4)  输出为:    " << S2.substr(-5, 4) << endl;
	try
	{
		cout << "  S2.substr(100, 4) 输出为:    " << S2.substr(100, 4) << endl;
	}
	catch (ERROR &e)
	{
		e.print();
		cout << endl;
	}
	try
	{
		cout << "  S2.substr(10, -4) 输出为:    " << S2.substr(10, -4) << endl;
	}
	catch (ERROR &e)
	{
		e.print();
		cout << endl;
	}
	cout << "  S0 = " << S0 << endl;
	cout << "  S2 = " << S2 << endl;
	cout << endl;
	cout << "5.c_str()测试" << endl;
	cout << "  S0.c_str()        输出为:    ";
	printf("%p\n", S0.c_str());
	cout << "  S2.c_str()        输出为:    ";
	printf("%p\n", S2.c_str());
	cout << endl;
	cout << "6.insert()测试" << endl;
	cout << "  S0.insert(0, \"Hello world!\")" << endl
		 << "                    输出为:    " << S0.insert(0, "Hello world!") << endl;
	cout << "  S2.insert(10, \"Hello world!\")" << endl
		 << "                    输出为:    " << S2.insert(10, "Hello world!") << endl;
	try
	{
		cout << "  S0.insert(6, S0)输出为:    " << S0.insert(6, S0) << endl;
	}
	catch (ERROR &e)
	{
		e.print();
		cout << endl;
	}
	try
	{
		cout << "  S2.insert(100, S0)  输出为:    " << S2.insert(100, S0) << endl;
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
	cout << "  ====重置S0, S2====" << endl;
	cout << "  S0 = \"\"" << endl
		 << "  S2 = \"This is a test.\"" << endl;
	cout << endl;
	cout << "7.find()测试" << endl;
	cout << "  S2.find(S4)       输出为:    " << S2.find(S4) << endl;
	cout << "  S4.find(S2)       输出为:    " << S4.find(S2) << endl;
	cout << "  S4.find(S0)       输出为:    " << S4.find(S0) << endl;
	cout << "  S2.find(\"test\")   输出为:    " << S2.find("test") << endl;
	cout << "  S2.find('t')      输出为:    " << S2.find('t') << endl;
	cout << endl;
	cout << "8.erase()测试" << endl;
	cout << "  S2.erase(10, 4)   输出为:    " << S2.erase(10, 4) << endl;
	cout << "  S2.erase(4)       输出为:    " << S2.erase(4) << endl;
	try
	{
		cout << "  S2.erase(100)     输出为:    " << S2.erase(100) << endl;
	}
	catch (ERROR &e)
	{
		e.print();
		cout << endl;
	}
	try
	{
		cout << "  S2.erase(0, -1)   输出为:    " << S2.erase(0, -1) << endl;
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
	cout << "  ======重置S2======" << endl;
	cout << "  S2 = \"This is a test.\"" << endl;
	cout << endl;
	cout << "9.replace()测试" << endl;
	cout << "  S2.replace(0, 4, S4)" << endl
		 << "                    输出为:    " << S2.replace(0, 4, S4) << endl;
	try
	{
		cout << "  S2.replace(10, 100, \"Hello world!\")" << endl
			 << "                    输出为:    " << S2.replace(10, 100, "Hello world!") << endl;
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
	cout << "  ======重置S2======" << endl;
	cout << "  S2 = \"This is a test.\"" << endl;
	cout << endl;
	cout << "10.trim()测试" << endl;
	S0 = "  test  ";
	S2 = "        This is a test.";
	cout << "  S0 = \"  test  \"" << endl
		 << "  S2 = \"        This is a test.\"" << endl;
	cout << endl;
	cout << "  S2.trim()         输出为:    " << S2.trim() << endl;
	cout << "  S4.trim()         输出为:    " << S4.trim() << endl;
	cout << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}