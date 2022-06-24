#include<bits/stdc++.h>
using namespace std;
struct LL{
	string num;
	short n[1005] = {0};
	int l;
};
istream &operator >> (istream &input, LL &nn)
{
	input >> nn.num;
	nn.l = nn.num.size();
	for(int i = nn.l; i >= 1; i--)
	{
		nn.n[nn.l - i + 1] = nn.num[i - 1] - '0';
	}
	return input;
}
ostream &operator << (ostream &output, LL &nn)
{
	output << nn.num;
	return output;
}

bool operator > (const LL &a, const LL &b)
{
	if(a.l > b.l)return true;
	if(a.l < b.l)return false;
	for(int i = a.l; i >= 1; i--)
	{
		if(a.n[i] > b.n[i])return true;
		if(a.n[i] < b.n[i])return false;
	}
		
	return false;
}
bool operator == (const LL &a, const LL &b)
{
	if(a.l != b.l)return false;
	for(int i = a.l; i >= 1; i--)
		if(a.n[i] != b.n[i])return false;	
	return true;
}
bool operator >= (const LL &a, const LL &b)
{
	if(a == b || a > b)return true;
	return false;
}
bool operator < (const LL &a, const LL &b)
{
	if(a >= b)return false;
	return true;
}
bool operator <= (const LL &a, const LL &b)
{
	if(a > b)return false;
	return true;
}
LL operator + (const LL &a, const LL &b)
{
	LL c;
	int la = a.l;
	int lb = b.l;
	c.l = max(a.l, b.l);
	for(int i = 1; i <= c.l; i++)
		c.n[i] = a.n[i] + b.n[i];
		
	for(int i = 1; i <= c.l - 1; i++)
	{
		c.n[i + 1] += c.n[i]/10;
		c.n[i] %= 10;
	}
	while(c.n[c.l]/10 != 0)
	{
		c.n[c.l + 1] += c.n[c.l]/10;
		c.n[c.l] %= 10;
		c.l++;
	}
		
	for(int i = c.l; i >= 1; i--)
	{
		//c.num[c.l - i] = c.n[i] + '0';
		c.num += (c.n[i] + '0');
	}
	c.num += '\0';
	return c;
}

LL operator - (const LL &a, const LL &b)
{
	LL c;
	//if(a < b)swap(a, b);
	c.l = max(a.l, b.l);
	for(int i = 1; i <= c.l; i++)
		c.n[i] = a.n[i] - b.n[i];			
	
	for(int i = 1; i <= c.l; i++)
	{
		if(c.n[i] < 0)
		{
			c.n[i] += 10;
			c.n[i + 1]--;
		}
	}
	/*
	for(int i = c.l; i >= 1; i--)
	{
		cout << c.n[i];
	}
	*/
	while(c.n[c.l] == 0 && c.l > 1)c.l--;
	
	for(int i = c.l; i >= 1; i--)
	{
		c.num += (c.n[i] + '0');
	}
	c.num += '\0';
	
	return c;
}

LL operator * (const LL &a, const LL &b)
{
	LL c;
	c.l = a.l + b.l;
	for(int i = 1; i <= a.l; i++)
	{
		for(int j = 1; j <= b.l; j++)
		{
			c.n[i + j - 1] += a.n[i] * b.n[j];
		}
	}
	for(int i = 1; i <= a.l + b.l - 1; i++)
	{
		c.n[i + 1] += c.n[i]/10;
		c.n[i] %= 10;
	}
	
	while(c.n[c.l] == 0 && c.l > 1)c.l--;
	
	for(int i = c.l; i >= 1; i--)
	{
		c.num += (c.n[i] + '0');
	}
	c.num += '\0';
	return c;
}

LL operator / (const LL &a1, const LL &b1)
{
	LL a, b, c;
	
	a = a1;
	b = b1;
	int t;
	t = a.l - b.l;
	
	if(a < b)
	{
		c.l = 1;
		c.num = "0";
		c.n[1] = 0;
		return c;
	}
	
	while(t >= 0)
	{
		b = b1;
		
		for(int i = b.l; i >= 1; i--)
			b.n[i + t] = b.n[i];
		for(int i = 1; i <= t; i++)
			b.n[i] = 0;
		b.l += t;
		//cout << b.l << endl;
		while(a >= b)
		{
			//cout << a << endl;
			a = a - b;
			c.n[t + 1]++;
		}	
		t--;
		//cout<<"d";
	}
	c.l = a1.l - b1.l + 1;
	
	while(c.n[c.l] == 0 && c.l > 1)c.l--;
	
	for(int i = c.l; i >= 1; i--)
	{
		c.num += (c.n[i] + '0');
	}
	c.num += '\0';
	
	return c;
	
}

LL operator % (const LL &a, const LL &b)
{
	//cout << "d" << endl;
	LL c;
	c = a - (a / b) * b;
	return c;
}

LL gcd(LL a, LL b)
{
	LL c;
	c.l = 1;
	c.num = "0";
	c.n[1] = 0;
	if(b == c)return a;
	return gcd(b, a % b);
}
LL gcd_beta(LL a, LL b)
{
	LL c;
	c.l = 1;
	c.num = "0";
	c.n[1] = 0;
	return (a % b == c)?c:(a % b);
}
int main()
{
	LL a, b, c;	
	
	cin >> a >> b;
	c = gcd(a, b);
	cout << c;
    system("pause");
	return 0;
}
