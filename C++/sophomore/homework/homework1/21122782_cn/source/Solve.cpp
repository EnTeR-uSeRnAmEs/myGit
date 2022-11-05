#include <bits/stdc++.h>
#include "..\head\Solve.h"
using namespace std;

pair<Complex, Complex> _solve(double a, double b, double c)
{
	Complex x1, x2;
	double delta = b * b - 4 * a * c;
	if (delta >= 0)
	{
		x1.real = (-b + sqrt(delta)) / (2 * a);
		x1.image = 0;
		x2.real = (-b - sqrt(delta)) / (2 * a);
		x2.image = 0;
	}
	else
	{
		x1.real = -b / (2 * a);
		x1.image = sqrt(-delta) / (2 * a);
		x2.real = -b / (2 * a);
		x2.image = -sqrt(-delta) / (2 * a);
	}
	return {x1, x2};
}
