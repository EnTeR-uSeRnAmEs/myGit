#include<bits/stdc++.h>
using namespace std;
int main()
{
	srand(time(NULL));
	for(int i = 1; i <= 200; i++)
	{
		for(int j = 1; j <= 1; j++)
		{
			int k = rand()%24 - 8;
			if(k == -1 || k == 7)k = 15;
			cout << k << " ";
		}
		
		int k = rand()%3;
		if(k == 0)cout << 250 << endl;
		else cout << 125 << endl;
	}
	return 0;
}
