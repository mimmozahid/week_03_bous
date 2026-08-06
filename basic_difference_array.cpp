#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    vector<int> v(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    
    vector<int> diff_arr(n+2), pre_sum(n+2);
    for (int i = 1; i <= q; i++)
    {
        int l, r, x;
        cin >> l >> r >> x;
        diff_arr[l] += x;
        diff_arr[r+1] -= x;
    }
    
    for (int i = 1; i <= n; i++)
    {
        pre_sum[i] = pre_sum[i-1] + diff_arr[i];
    }

    for (int i = 1; i <= n; i++)
    {
        cout << pre_sum[i]+v[i] << " ";
    }
    
    cout << endl;
    
    return 0;
}