#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    map<int, vector<int>> data;
    vector<int> key;
    cin >> n >> m;
    while (n--)
    {
        int time1, time2, money;
        cin >> time1 >> time2 >> money;
        key.push_back(money);
        data[money].push_back(time1 * 60 + time2);
    }
    sort(key.begin(), key.end());
    for (int i = key.size() - 1; i >= 0 && m != 0; --i)
    {
        sort(data[key[i]].begin(), data[key[i]].end());
        for (unsigned int j = 0; j < data[key[i]].size() && m != 0; ++j)
        {
            cout << data[key[i]][j] / 60 << " " << data[key[i]][j] % 60 << " " << key[i] << endl;
            --m;
        }
    }
    // return 0;
    system("pause");
}