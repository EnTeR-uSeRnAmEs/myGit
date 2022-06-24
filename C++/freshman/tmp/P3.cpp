#include <iostream>
#include <stack>
#include <map>
#include <string>
#include <cstdio>
using namespace std;
map<char, int> p;

stack<double> num;
stack<char> op;

void func(stack<double> num, stack<char> op)
{
	while (op.top() != '#' && op.top() != '(')
	{
		double tmp;
		double a = num.top();
		num.pop();
		if (num.empty())
		{
			num.push(a);
			break;
		}
		else
		{
			double b = num.top();
			num.pop();
			switch (op.top())
			{
			case '+':
				tmp = b + a;
				break;
			case '-':
				tmp = b - a;
				break;
			case '*':
				tmp = b * a;
				break;
			case '/':
				tmp = b / a;
				break;
			default:
				break;
			}
			op.pop();
			num.push(tmp);
		}
	}
}
int main()
{
	string str;
	double temp;
	char ch;
	p['+'] = p['-'] = 1;
	p['*'] = p['/'] = 2;
	p['#'] = 0;
	cin >> str;
	ch = '#';
	op.push(ch);
	double t;
	bool flag;
	for (int i = 0; i < int(str.length());)
	{
		if (isdigit(str[i]) || str[i] == '.')
		{
			flag = true;
			t = 0.1;
			if (isdigit(str[i]))
				temp = str[i] - '0';
			else
				flag = false;
			i++;
			while (i < str.length() && (isdigit(str[i]) || (str[i] == '.')))
			{
				if (isdigit(str[i]) && flag)
				{
					temp = temp * 10 + str[i] - '0';
					i++;
				}
				else if (str[i] == '.')
				{
					flag = false;
					i++;
				}
				else
				{
					if (isdigit(str[i]))
					{
						temp = temp + (str[i] - '0') * t;
						t = t * 0.1;
						i++;
					}
				}
			}
			num.push(temp);
		}
		else if (str[i] == '(')
		{
			op.push(str[i]);
			i++;
		}
		else if (str[i] == ')')
		{
			while (!op.empty() && op.top() != '(')
			{
				func(num, op);
			}
			op.pop();
			i++;
		}
		else if (str[i] == '=' || str[i] == ' ')
		{
			i++;
		}
		else
		{
			while (op.top() != '#' && p[op.top()] >= p[str[i]])
			{
				func(num, op);
			}
			op.push(str[i]);
			i++;
			cout << 5;
		}
	}
	while (op.top() != '#')
	{
		func(num, op);
	}
	cout << num.top() << endl;
}