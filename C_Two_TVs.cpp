#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    map <int, int> d;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;

        d[l]++;
        d[r+1]--;
    }

    ll sum = 0;

    for (auto [idx, val] : d)
    {
        sum += val;
        if (sum > 2)
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    
    cout << "YES" << endl;
    
    return 0;
}