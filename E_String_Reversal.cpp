#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
using ll = long long;

template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    string s;
    cin >> n;
    cin >> s;

    string r = s;
    reverse (r.begin(), r.end ());

    map<char, vector<int>> cnts, cntr;
    for (int i = 0; i < n; i++)
    {
        cnts[s[i]].push_back(i);
        cntr[r[i]].push_back(i);
    }
    
    vector<int> per(n);
    for (char c = 'a'; c <= 'z'; c++)
    {
        for (int i = 0; i < cnts[c].size(); i++)
        {
            per[cntr[c][i]] = cnts[c][i];
        }
    }
    
    pbds<int> p;
    ll ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        ans += p.order_of_key(per[i]);
        p.insert(per[i]);
    }
    cout << ans << endl;
    
    return 0;
}