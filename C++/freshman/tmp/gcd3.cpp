#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	//若a<b ,交换两值
	int temp1;
	if (a < b) {
		temp1 = a;
		a = b;
		b = temp1;
	}
	//求最大公约数
	while (b != 0) {
		int temp2 = b;
		b = a % b;
		a = temp2;
	}
	return a;
}


int main()
{
    int a, b;
    while (cin >> a >> b) cout << gcd(a, b) << endl;
    system("pause");
    return 0;
}