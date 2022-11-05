#include <iostream>
#include <vector>
#include "Vector.h"
using namespace std;

void test01()
{
	cout << "------------- ���캯���Ĳ��� -------------" << endl;
	Vector<int> vi1;
	cout << "1. Vector<int> vi1        vi1�ĸ���Ϊ: " << vi1.getsize() << " , vi1������Ϊ: " << vi1.getcapacity() << endl;
	Vector<char> vc1(10);
	cout << "2. Vector<char> vc1(10)   vc1�ĸ���Ϊ: " << vc1.getsize() << " , vc1������Ϊ: " << vc1.getcapacity() << endl;
	Vector<char> vc2(vc1);
	cout << "3. Vector<char> vc2(vc1)  vc2�ĸ���Ϊ: " << vc2.getsize() << " , vc2������Ϊ: " << vc2.getcapacity() << endl;
	cout << endl;
	cout << "------------- ��������صĲ��� -------------" << endl;
	cout << "1.\"<<\" �� \">>\" ����" << endl;
	cout << "  (1)����0-9��vi1   ";
	// cin >> vi1;
	for (int i = 0; i < 10; i++)
	{
		vi1.push_back(i);
	}
	cout << "   vi1������� " << vi1 << "  vi1�ĸ���Ϊ: " << vi1.getsize() << " , vi1������Ϊ : " << vi1.getcapacity() << endl;
	cout << endl;
	cout << "  (2)����A-J��vc1   ";
	// cin >> vc1;
	for (int i = 0; i < 10; i++)
	{
		vc1.push_back('A' + i);
	}
	cout << "   vc1������� " << vc1 << "  vc1�ĸ���Ϊ: " << vc1.getsize() << " , vc1������Ϊ : " << vc1.getcapacity() << endl;
	cout << endl;
	cout << "2.\"+\" , \"+=\" �� \"=\" ����" << endl;
	cout << "  �ֱ��� 10-19 �� 20-25 ����vi2��vi3" << endl;
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
	cout << "  (1)vi4 = vi1 + vi2 + vi1  ���Ϊ:  " << vi4 << endl;
	cout << "     vi4 = vi1 + vi3        ���Ϊ:  ";
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
	cout << "  vc2����10��'0'" << endl;
	vc3 = vc1 + vc2;
	cout << "     vc3 = vc1 + vc2        ���Ϊ:  " << vc3 << endl;
	vi4 += vi1 += vi2;
	cout << "\n  (2)vi4 += vi1 += vi2      ���Ϊ:   vi1 " << vi1 << endl;
	cout << "                                      vi4 " << vi4 << endl;
	cout << "     vi4 += vi3             ���Ϊ:   ";
	try
	{
		vi4 += vi3;
	}
	catch (ERROR &e)
	{
		e.print();
		cout << endl;
	}
	cout << "\n3.\"==\" �� \"!=\" ����" << endl;
	cout << "  �ֱ���vc1��vi1����vc4��vi5" << endl;
	Vector<char> vc4(vc1);
	Vector<int> vi5(vi1);
	cout << "  (1)vc1 == vc1 ?  ���Ϊ:  " << (vc1 == vc1) << endl;
	cout << "     vc4 == vc1 ?  ���Ϊ:  " << (vc4 == vc1) << endl;
	cout << "     vi5 == vi1 ?  ���Ϊ:  " << (vi5 == vi1) << endl;
	cout << "     vi1 == vi4 ?  ���Ϊ:  " << (vi1 == vi4) << endl;
	cout << "\n  (2)vc1 != vc1 ?  ���Ϊ:  " << (vc1 != vc1) << endl;
	cout << "     vc4 != vc1 ?  ���Ϊ:  " << (vc4 != vc1) << endl;
	cout << "     vi5 != vi1 ?  ���Ϊ:  " << (vi5 != vi1) << endl;
	cout << "     vi1 != vi4 ?  ���Ϊ:  " << (vi1 != vi4) << endl;
	cout << "\n4.\"[]\" ����" << endl;
	cout << "  (1)vi1������9��0�����  ";
	for (int i = 9; i > -1; i--)
	{
		if (i != 0)
		{
			cout << vi1[i] << " ";
		}
		else
			cout << vi1[i] << endl;
	}
	cout << "     vc1������9��0�����  ";
	for (int i = 9; i > -1; i--)
	{
		if (i != 0)
		{
			cout << vc1[i] << " ";
		}
		else
			cout << vc1[i] << endl;
	}
	cout << "     ���� vc1[10]��   ";
	try
	{
		vc1[10];
	}
	catch (ERROR &e)
	{
		e.print();
		cout << endl;
	}
	cout << "     ���� vi1[-10]��  ";
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
	cout << "  (2)vi1[0] = -1      ���Ϊ��  " << vi1 << endl;
	vc1[9] = vc1[0];
	cout << "     vc1[9] = vc1[0]  ���Ϊ��  " << vc1 << endl;
	cout << "\n------------- ��Ա�����Ĳ��� -------------" << endl;
	cout << "1.push_back()����" << endl;
	vi1.push_back(11);
	vc1.push_back('K');
	cout << "   vi1.push_back(11)   ���Ϊ��  " << vi1 << endl;
	cout << "   vc1.push_back('K')  ���Ϊ��  " << vc1 << endl;
	cout << "\n2.pop_back()����" << endl;
	vi1.pop_back();
	vc1.pop_back();
	cout << "   vi1.pop_back()      ���Ϊ��  " << vi1 << endl;
	cout << "   vc1.pop_back()      ���Ϊ��  " << vc1 << endl;
	cout << "\n2.begin() �� end() ����" << endl;
	Vector<int> vi6;
	Vector<char> vc5;
	cout << "   �ֱ���յ�vi6��vc5" << endl;
	cout << "   (1)*vi1.begin()       ���Ϊ��  " << *vi1.begin() << endl;
	cout << "      *vc1.begin()       ���Ϊ��  " << *vc1.begin() << endl;
	cout << "      *vi6.begin()       ���Ϊ��  ";
	try
	{
		*vi6.begin();
	}
	catch (ERROR &e)
	{
		e.print();
		cout << endl;
	}
	cout << "      *vc5.begin()       ���Ϊ��  ";
	try
	{
		*vc5.begin();
	}
	catch (ERROR &e)
	{
		e.print();
		cout << endl;
	}
	cout << "\n   (2)*(vi1.end()-1)     ���Ϊ��  " << *(vi1.end() - 1) << endl;
	cout << "      *(vc1.end()-1)     ���Ϊ��  " << *(vc1.end() - 1) << endl;
	cout << "      *(vi6.end()-1)     ���Ϊ��  ";
	try
	{
		*(vi6.end() - 1);
	}
	catch (ERROR &e)
	{
		e.print();
		cout << endl;
	}
	cout << "      *(vc5.end()-1)     ���Ϊ��  ";
	try
	{
		*(vc5.end() - 1);
	}
	catch (ERROR &e)
	{
		e.print();
		cout << endl;
	}
	cout << "\n3.front() �� back() ����" << endl;
	cout << "   (1)vi1.front()       ���Ϊ��  " << vi1.front() << endl;
	cout << "      vc1.front()       ���Ϊ��  " << vc1.front() << endl;
	cout << "      vi6.front()       ���Ϊ��  ";
	try
	{
		vi6.front();
	}
	catch (ERROR &e)
	{
		e.print();
		cout << endl;
	}
	cout << "      vc5.front()       ���Ϊ��  ";
	try
	{
		vc5.front();
	}
	catch (ERROR &e)
	{
		e.print();
		cout << endl;
	}
	cout << "\n   (2)vi1.back()        ���Ϊ��  " << vi1.back() << endl;
	cout << "      vc1.back()        ���Ϊ��  " << vc1.back() << endl;
	cout << "      vi6.back()        ���Ϊ��  ";
	try
	{
		vi6.back();
	}
	catch (ERROR &e)
	{
		e.print();
		cout << endl;
	}
	cout << "      vc5.back()        ���Ϊ��  ";
	try
	{
		vc5.back();
	}
	catch (ERROR &e)
	{
		e.print();
		cout << endl;
	}
	cout << "\n4.insert()����" << endl;
	vi1.insert(vi1.begin() + 1, 8);
	vc1.insert(vc1.begin() + 1, 'Z');
	cout << "    vi1.insert(vi1.begin()+1, 8)        ���Ϊ��  " << vi1 << endl;
	cout << "    vc1.insert(vc1.begin()+1, 'Z')      ���Ϊ��  " << vc1 << endl;
	cout << "    vi1.insert(vi1.begin()-1, -1)       ���Ϊ��  ";
	try
	{
		vi1.insert(vi1.begin() - 1, -1);
	}
	catch (ERROR &e)
	{
		e.print();
		cout << endl;
	}
	cout << "    vc1.insert(vc1.end()+1, 'X')        ���Ϊ��  ";
	try
	{
		vc1.insert(vc1.end() + 1, 'X');
	}
	catch (ERROR &e)
	{
		e.print();
		cout << endl;
	}
	cout << "\n5.erase()����" << endl;
	vi1.erase(vi1.begin() + 1);
	vc1.erase(vc1.begin() + 1);
	cout << "    vi1.erase(vi1.begin()+1)        ���Ϊ��  " << vi1 << endl;
	cout << "    vc1.erase(vc1.begin()+1)        ���Ϊ��  " << vc1 << endl;
	cout << "    vi1.erase(vi1.begin()-1)        ���Ϊ��  ";
	try
	{
		vi1.erase(vi1.begin() - 1);
	}
	catch (ERROR &e)
	{
		e.print();
		cout << endl;
	}
	cout << "    vc1.erase(vc1.end()+1)          ���Ϊ��  ";
	try
	{
		vc1.erase(vc1.end() + 1);
	}
	catch (ERROR &e)
	{
		e.print();
		cout << endl;
	}
	cout << "\n6.find()����" << endl;
	cout << "    *vi1.find(vi1.begin(), 16);        ���Ϊ��  " << *vi1.find(vi1.begin(), 16) << endl;
	cout << "    *vc1.find(vc1.begin(), 'E');       ���Ϊ��  " << *vc1.find(vc1.begin(), 'E') << endl;
	cout << "    *vi1.find(vi1.begin()-1, 16)       ���Ϊ��  ";
	try
	{
		*vi1.find(vi1.begin() - 1, 16);
	}
	catch (ERROR &e)
	{
		e.print();
		cout << endl;
	}
	cout << "    *vc1.find(vc1.end()+1, 'E')        ���Ϊ��  ";
	try
	{
		*vc1.find(vc1.end() + 1, 'E');
	}
	catch (ERROR &e)
	{
		e.print();
		cout << endl;
	}
	cout << "  û�ҵ��������" << endl;
	cout << "    *vi3.find(vi3.begin(), -4);        ���Ϊ��  " << *vi3.find(vi3.begin(), -4) << endl;
	cout << "    *vc2.find(vc2.begin(), 'X');       ���Ϊ��  " << *vc2.find(vc2.begin(), 'X') << endl;
	cout << "\n7.getsize() �� getcapacity() ����" << endl;
	cout << "    vi1�ĸ���Ϊ��" << vi1.getsize() << " , vi1������Ϊ��" << vi1.getcapacity() << endl;
	cout << "    vc1�ĸ���Ϊ��" << vc1.getsize() << " , vc1������Ϊ��" << vc1.getcapacity() << endl;
	cout << "    vi6�ĸ���Ϊ��" << vi6.getsize() << "  , vi6������Ϊ��" << vi6.getcapacity() << endl;
	cout << "\n8.empty() ����" << endl;
	cout << "    vi1.empty()        ���Ϊ��  " << vi1.empty() << endl;
	cout << "    vc1.empty()        ���Ϊ��  " << vc1.empty() << endl;
	cout << "    vi6.empty()        ���Ϊ��  " << vi6.empty() << endl;
	cout << "    vc5.empty()        ���Ϊ��  " << vc5.empty() << endl;
	cout << "\n9.clear() ����" << endl;
	vi1.clear();
	vc1.clear();
	cout << "    vi1.clear()        vi1��" << vi1 << " vi1�ĸ���Ϊ��" << vi1.getsize() << " , vi1������Ϊ��" << vi1.getcapacity() << endl;
	cout << "    vc1.clear()        vc1��" << vc1 << " vc1�ĸ���Ϊ��" << vc1.getsize() << " , vc1������Ϊ��" << vc1.getcapacity() << endl;
}

int main()
{
	test01();
	return 0;
}

/*
-1.����
(1)Vector()
(2)Vector(Vector &v)
0.���������
���ԣ�

-2.����
empty  ��������Ƿ�Ϊ��

size�������ɵ�Ԫ����

capacity
���ص�ǰ�洢�ռ��ܹ����ɵ�Ԫ����

-3.Ԫ�ط���
front()

back()

-4.��ַ����
begin() ����ͷ��ַ

end()����β��ַ


1.push_back(ele)
2.ɾ��
pop_back()
erase(pos)
clear()
4.insert(pos, strele) ��pos�����ele
5.find(ele, pos) ��pos��ʼ��eleԪ�أ��ҵ����ظ�Ԫ�ص��±꣬����-1



*/