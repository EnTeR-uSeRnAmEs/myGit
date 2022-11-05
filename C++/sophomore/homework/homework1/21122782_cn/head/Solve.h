//#pragma once
#include <bits/stdc++.h>
#ifndef _SOLVE_H
#define _SOLVE_H
using namespace std;

struct Complex
{
	double real;
	double image = 0;
};

pair<Complex, Complex> _solve(double a, double b, double c);
#endif
