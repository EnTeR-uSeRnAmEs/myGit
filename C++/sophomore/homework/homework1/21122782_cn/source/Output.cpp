#include <bits/stdc++.h>
#include "..\head\Solve.h"
#include "..\head\Output.h"
using namespace std;

void Func(const Complex &ans)
{
	if (ans.real != 0)
	{
		cout << " " << ans.real;
		if (ans.image > 0)
		{
			if (ans.image != 1)
				cout << " + " << ans.image << "i";
			else
				cout << " + i";
		}
		else if (ans.image < 0)
		{
			if (ans.image != -1)
				cout << " - " << ans.image << "i";
			else
				cout << " - i";
		}
	}
	else
	{
		if (ans.image > 0)
		{
			if (ans.image != 1)
				cout << " " << ans.image << "i";
			else
				cout << " i";
		}
		else if (ans.image < 0)
		{
			if (ans.image != -1)
				cout << " " << ans.image << "i";
			else
				cout << " -i";
		}
	}
	cout << endl;
}

void Solve(double a, double b, double c)
{
	Complex ans1, ans2;
	tie(ans1, ans2) = _solve(a, b, c);
	cout << "x1 =";
	Func(ans1);
	cout << "x2 =";
	Func(ans2);
}
