#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (auto &x : v) cin >> x;

    vector<int> d (n+1);
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        --l, --r;
        d[l]++;
        d[r+1]--;
    }
    
    for (int i = 1; i <= n; i++)
    {
        d[i] = d[i] + d[i-1];
    }
    
    sort (d.rbegin (), d.rend ());
    sort (v.rbegin (), v.rend ());

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += (1LL * v[i]*d[i]);
    }
    
    cout << ans << endl;
    // for (auto x : d) cout << x << " ";
    // cout << endl;
    
    return 0;
}