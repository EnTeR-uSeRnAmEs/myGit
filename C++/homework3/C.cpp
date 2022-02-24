#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int n, i, num = 1;
	vector <int> a;
	while (cin >> n) {
		a.push_back(n);
		while (cin.peek() != '\n') 
        {
			cin >> n;
			a.push_back(n);
		}

		while (cin >> n) 
        {
			a.push_back(n);
			while (cin.peek() != '\n') 
            {
				cin >> n;
				a.push_back(n);
			}
			break;
		}

		sort(a.begin(), a.begin() + a.size());
		cout << "Case " << num << ": ";
		for (int i = 0; i < a.size(); i++) 
        {

			if (i == a.size() - 1) cout << a[i] << endl;
			else cout << a[i] << " ";
		}
		num++;
		a.clear();
	}
    system("pause");
    return 0;
}