#include <iostream>
#include <vector>
#include "Vector.h"
using namespace std;

void test01()
{
	cout << "------------- 构造函数的测试 -------------" << endl;
	Vector<int> vi1;
	cout << "1. Vector<int> vi1        vi1的个数为: " << vi1.getsize() << " , vi1的容量为: " << vi1.getcapacity() << endl;
	Vector<char> vc1(10);
	cout << "2. Vector<char> vc1(10)   vc1的个数为: " << vc1.getsize() << " , vc1的容量为: " << vc1.getcapacity() << endl;
	Vector<char> vc2(vc1);
	cout << "3. Vector<char> vc2(vc1)  vc2的个数为: " << vc2.getsize() << " , vc2的容量为: " << vc2.getcapacity() << endl;
	cout << endl;
	cout << "------------- 运算符重载的测试 -------------" << endl;
	cout << "1.\"<<\" 和 \">>\" 重载" << endl;
	cout << "  (1)输入0-9到vi1   ";
	// cin >> vi1;
	for (int i = 0; i < 10; i++)
	{
		vi1.push_back(i);
	}
	cout << "   vi1的输出： " << vi1 << "  vi1的个数为: " << vi1.getsize() << " , vi1的容量为 : " << vi1.getcapacity() << endl;
	cout << endl;
	cout << "  (2)输入A-J到vc1   ";
	// cin >> vc1;
	for (int i = 0; i < 10; i++)
	{
		vc1.push_back('A' + i);
	}
	cout << "   vc1的输出： " << vc1 << "  vc1的个数为: " << vc1.getsize() << " , vc1的容量为 : " << vc1.getcapacity() << endl;
	cout << endl;
	cout << "2.\"+\" , \"+=\" 和 \"=\" 重载" << endl;
	cout << "  分别用 10-19 和 20-25 创建vi2和vi3" << endl;
	Vector<int> vi2(10);
	for (int i = 10; i < 20; i++)
	{
		vi2.push_back(i);
	}
	Vector<int> vi3(6);
	for (int i = 20; i < 26; i++)
	{
		vi3.push_back(i);
	}
	Vector<int> vi4 = vi1 + vi2 + vi1;
	cout << "  (1)vi4 = vi1 + vi2 + vi1  输出为:  " << vi4 << endl;
	cout << "     vi4 = vi1 + vi3        输出为:  ";
	try
	{
		vi1 + vi3;
	}
	catch (ERROR &e)
	{
		e.print();
		cout << endl;
	}
	Vector<char> vc3;
	for (int i = 0; i < 10; i++)
	{
		vc2.push_back('0');
	}
	cout << "  vc2加入10个'0'" << endl;
	vc3 = vc1 + vc2;
	cout << "     vc3 = vc1 + vc2        输出为:  " << vc3 << endl;
	vi4 += vi1 += vi2;
	cout << "\n  (2)vi4 += vi1 += vi2      输出为:   vi1 " << vi1 << endl;
	cout << "                                      vi4 " << vi4 << endl;
	cout << "     vi4 += vi3             输出为:   ";
	try
	{
		vi4 += vi3;
	}
	catch (ERROR &e)
	{
		e.print();
		cout << endl;
	}
	cout << "\n3.\"==\" 和 \"!=\" 重载" << endl;
	cout << "  分别用vc1、vi1构造vc4、vi5" << endl;
	Vector<char> vc4(vc1);
	Vector<int> vi5(vi1);
	cout << "  (1)vc1 == vc1 ?  结果为:  " << (vc1 == vc1) << endl;
	cout << "     vc4 == vc1 ?  结果为:  " << (vc4 == vc1) << endl;
	cout << "     vi5 == vi1 ?  结果为:  " << (vi5 == vi1) << endl;
	cout << "     vi1 == vi4 ?  结果为:  " << (vi1 == vi4) << endl;
	cout << "\n  (2)vc1 != vc1 ?  结果为:  " << (vc1 != vc1) << endl;
	cout << "     vc4 != vc1 ?  结果为:  " << (vc4 != vc1) << endl;
	cout << "     vi5 != vi1 ?  结果为:  " << (vi5 != vi1) << endl;
	cout << "     vi1 != vi4 ?  结果为:  " << (vi1 != vi4) << endl;
	cout << "\n4.\"[]\" 重载" << endl;
	cout << "  (1)vi1索引从9到0输出：  ";
	for (int i = 9; i > -1; i--)
	{
		if (i != 0)
		{
			cout << vi1[i] << " ";
		}
		else
			cout << vi1[i] << endl;
	}
	cout << "     vc1索引从9到0输出：  ";
	for (int i = 9; i > -1; i--)
	{
		if (i != 0)
		{
			cout << vc1[i] << " ";
		}
		else
			cout << vc1[i] << endl;
	}
	cout << "     访问 vc1[10]：   ";
	try
	{
		vc1[10];
	}
	catch (ERROR &e)
	{
		e.print();
		cout << endl;
	}
	cout << "     访问 vi1[-10]：  ";
	try
	{
		vi1[-10];
	}
	catch (ERROR &e)
	{
		e.print();
		cout << endl;
	}
	cout << endl;
	vi1[0] = -1;
	cout << "  (2)vi1[0] = -1      输出为：  " << vi1 << endl;
	vc1[9] = vc1[0];
	cout << "     vc1[9] = vc1[0]  输出为：  " << vc1 << endl;
	cout << "\n------------- 成员函数的测试 -------------" << endl;
	cout << "1.push_back()测试" << endl;
	vi1.push_back(11);
	vc1.push_back('K');
	cout << "   vi1.push_back(11)   输出为：  " << vi1 << endl;
	cout << "   vc1.push_back('K')  输出为：  " << vc1 << endl;
	cout << "\n2.pop_back()测试" << endl;
	vi1.pop_back();
	vc1.pop_back();
	cout << "   vi1.pop_back()      输出为：  " << vi1 << endl;
	cout << "   vc1.pop_back()      输出为：  " << vc1 << endl;
	cout << "\n2.begin() 和 end() 测试" << endl;
	Vector<int> vi6;
	Vector<char> vc5;
	cout << "   分别构造空的vi6和vc5" << endl;
	cout << "   (1)*vi1.begin()       输出为：  " << *vi1.begin() << endl;
	cout << "      *vc1.begin()       输出为：  " << *vc1.begin() << endl;
	cout << "      *vi6.begin()       输出为：  ";
	try
	{
		*vi6.begin();
	}
	catch (ERROR &e)
	{
		e.print();
		cout << endl;
	}
	cout << "      *vc5.begin()       输出为：  ";
	try
	{
		*vc5.begin();
	}
	catch (ERROR &e)
	{
		e.print();
		cout << endl;
	}
	cout << "\n   (2)*(vi1.end()-1)     输出为：  " << *(vi1.end() - 1) << endl;
	cout << "      *(vc1.end()-1)     输出为：  " << *(vc1.end() - 1) << endl;
	cout << "      *(vi6.end()-1)     输出为：  ";
	try
	{
		*(vi6.end() - 1);
	}
	catch (ERROR &e)
	{
		e.print();
		cout << endl;
	}
	cout << "      *(vc5.end()-1)     输出为：  ";
	try
	{
		*(vc5.end() - 1);
	}
	catch (ERROR &e)
	{
		e.print();
		cout << endl;
	}
	cout << "\n3.front() 和 back() 测试" << endl;
	cout << "   (1)vi1.front()       输出为：  " << vi1.front() << endl;
	cout << "      vc1.front()       输出为：  " << vc1.front() << endl;
	cout << "      vi6.front()       输出为：  ";
	try
	{
		vi6.front();
	}
	catch (ERROR &e)
	{
		e.print();
		cout << endl;
	}
	cout << "      vc5.front()       输出为：  ";
	try
	{
		vc5.front();
	}
	catch (ERROR &e)
	{
		e.print();
		cout << endl;
	}
	cout << "\n   (2)vi1.back()        输出为：  " << vi1.back() << endl;
	cout << "      vc1.back()        输出为：  " << vc1.back() << endl;
	cout << "      vi6.back()        输出为：  ";
	try
	{
		vi6.back();
	}
	catch (ERROR &e)
	{
		e.print();
		cout << endl;
	}
	cout << "      vc5.back()        输出为：  ";
	try
	{
		vc5.back();
	}
	catch (ERROR &e)
	{
		e.print();
		cout << endl;
	}
	cout << "\n4.insert()测试" << endl;
	vi1.insert(vi1.begin() + 1, 8);
	vc1.insert(vc1.begin() + 1, 'Z');
	cout << "    vi1.insert(vi1.begin()+1, 8)        输出为：  " << vi1 << endl;
	cout << "    vc1.insert(vc1.begin()+1, 'Z')      输出为：  " << vc1 << endl;
	cout << "    vi1.insert(vi1.begin()-1, -1)       输出为：  ";
	try
	{
		vi1.insert(vi1.begin() - 1, -1);
	}
	catch (ERROR &e)
	{
		e.print();
		cout << endl;
	}
	cout << "    vc1.insert(vc1.end()+1, 'X')        输出为：  ";
	try
	{
		vc1.insert(vc1.end() + 1, 'X');
	}
	catch (ERROR &e)
	{
		e.print();
		cout << endl;
	}
	cout << "\n5.erase()测试" << endl;
	vi1.erase(vi1.begin() + 1);
	vc1.erase(vc1.begin() + 1);
	cout << "    vi1.erase(vi1.begin()+1)        输出为：  " << vi1 << endl;
	cout << "    vc1.erase(vc1.begin()+1)        输出为：  " << vc1 << endl;
	cout << "    vi1.erase(vi1.begin()-1)        输出为：  ";
	try
	{
		vi1.erase(vi1.begin() - 1);
	}
	catch (ERROR &e)
	{
		e.print();
		cout << endl;
	}
	cout << "    vc1.erase(vc1.end()+1)          输出为：  ";
	try
	{
		vc1.erase(vc1.end() + 1);
	}
	catch (ERROR &e)
	{
		e.print();
		cout << endl;
	}
	cout << "\n6.find()测试" << endl;
	cout << "    *vi1.find(vi1.begin(), 16);        输出为：  " << *vi1.find(vi1.begin(), 16) << endl;
	cout << "    *vc1.find(vc1.begin(), 'E');       输出为：  " << *vc1.find(vc1.begin(), 'E') << endl;
	cout << "    *vi1.find(vi1.begin()-1, 16)       输出为：  ";
	try
	{
		*vi1.find(vi1.begin() - 1, 16);
	}
	catch (ERROR &e)
	{
		e.print();
		cout << endl;
	}
	cout << "    *vc1.find(vc1.end()+1, 'E')        输出为：  ";
	try
	{
		*vc1.find(vc1.end() + 1, 'E');
	}
	catch (ERROR &e)
	{
		e.print();
		cout << endl;
	}
	cout << "  没找到的情况：" << endl;
	cout << "    *vi3.find(vi3.begin(), -4);        输出为：  " << *vi3.find(vi3.begin(), -4) << endl;
	cout << "    *vc2.find(vc2.begin(), 'X');       输出为：  " << *vc2.find(vc2.begin(), 'X') << endl;
	cout << "\n7.getsize() 和 getcapacity() 测试" << endl;
	cout << "    vi1的个数为：" << vi1.getsize() << " , vi1的容量为：" << vi1.getcapacity() << endl;
	cout << "    vc1的个数为：" << vc1.getsize() << " , vc1的容量为：" << vc1.getcapacity() << endl;
	cout << "    vi6的个数为：" << vi6.getsize() << "  , vi6的容量为：" << vi6.getcapacity() << endl;
	cout << "\n8.empty() 测试" << endl;
	cout << "    vi1.empty()        输出为：  " << vi1.empty() << endl;
	cout << "    vc1.empty()        输出为：  " << vc1.empty() << endl;
	cout << "    vi6.empty()        输出为：  " << vi6.empty() << endl;
	cout << "    vc5.empty()        输出为：  " << vc5.empty() << endl;
	cout << "\n9.clear() 测试" << endl;
	vi1.clear();
	vc1.clear();
	cout << "    vi1.clear()        vi1：" << vi1 << " vi1的个数为：" << vi1.getsize() << " , vi1的容量为：" << vi1.getcapacity() << endl;
	cout << "    vc1.clear()        vc1：" << vc1 << " vc1的个数为：" << vc1.getsize() << " , vc1的容量为：" << vc1.getcapacity() << endl;
}

int main()
{
	test01();
	return 0;
}

/*
-1.构造
(1)Vector()
(2)Vector(Vector &v)
0.运算符重载
测试：

-2.容量
empty  检查容器是否为空

size返回容纳的元素数

capacity
返回当前存储空间能够容纳的元素数

-3.元素访问
front()

back()

-4.地址访问
begin() 返回头地址

end()返回尾地址


1.push_back(ele)
2.删除
pop_back()
erase(pos)
clear()
4.insert(pos, strele) 在pos后插入ele
5.find(ele, pos) 从pos开始找ele元素，找到返回该元素的下标，否则-1



*/