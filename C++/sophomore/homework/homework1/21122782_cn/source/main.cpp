#include <bits/stdc++.h>
#include "..\head\Solve.h"
#include "..\head\Output.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int main()
{
	//	std::cout << "test" << std::endl;
	double a, b, c;
	cout << "������һԪ���η��� ax^2 + bx + c = 0 ����������������0�����������ַ����˳�: ";
	while (cin >> a >> b >> c)
	{
		if (a == 0)
		{
			cout << "��������..." << endl;
			break;
		}
		else
			Solve(a, b, c);
		system("pause");
		system("cls");
		cout << "������һԪ���η��� ax^2 + bx + c = 0 ����������������0�����������ַ����˳�: ";
	}

	// system("pause");
	return 0;
}
