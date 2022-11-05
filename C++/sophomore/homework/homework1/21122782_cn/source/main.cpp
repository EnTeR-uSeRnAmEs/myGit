#include <bits/stdc++.h>
#include "..\head\Solve.h"
#include "..\head\Output.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int main()
{
	//	std::cout << "test" << std::endl;
	double a, b, c;
	cout << "请输入一元二次方程 ax^2 + bx + c = 0 的三个参数，输入0或其他任意字符以退出: ";
	while (cin >> a >> b >> c)
	{
		if (a == 0)
		{
			cout << "结束运行..." << endl;
			break;
		}
		else
			Solve(a, b, c);
		system("pause");
		system("cls");
		cout << "请输入一元二次方程 ax^2 + bx + c = 0 的三个参数，输入0或其他任意字符以退出: ";
	}

	// system("pause");
	return 0;
}
