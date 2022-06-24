#include <bits/stdc++.h>
using namespace std;
int main()
{
	double a[21] = {0};
	int b, i = 1, j, t = 1, m;
	double p1, p2, x1, x2, x3, p3, q3, q1, q2;
	for (int i = 0; cin >> a[i]; i++) 
	{
		p1 = 0, p2 = 0, x1 = 0, x2 = 1, b = 0, q1 = 0, q2 = 0, q3 = 0;
		if (cin.peek() == '\n')
		{
			while (x2 - x1 >= 1e-8)
			{
				cout << x1 << "  " << x2 << endl;
				p1 = p2 = p3 = 0;
				for (j = m; j >= 0; j--)
				{
					if (x1 == 0 && m == 0)
					{
						p1 = a[m];
					}
					else
					{
						q1 = pow(x1, j);
						p1 = a[m - j] * q1 + p1;
					}
				}
				for (j = m; j >= 0; j--)
				{
					q2 = pow(x2, j);
					p2 = a[m - j] * q2 + p2;
				}
				x3 = (x1 + x2) / 2;
				for (j = m; j >= 0; j--)
				{
					q3 = pow(x3, j);
					p3 = a[m - j] * q3 + p3;
				}

				if (p3 == 0)
				{
					break;
				}
				else if (p3 * p1 < 0)
				{
					x2 = x3;
				}
				else if (p2 * p3 < 0)
				{
					x1 = x3;
				}
				b++;
			}
			cout << "Case " << int(t) << ": " << x3 << endl;
			t++;
		}
	}
	return 0;
}
