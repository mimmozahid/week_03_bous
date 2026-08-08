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
    
    int n, k;
    cin >> n >> k;
    vector<int> v(n), ans;
    for (auto &x : v) cin >> x;

    pbds <pair<int, int>> p;
    
    
    int l = 0;
    for (int r = 0; r < n; r++) 
    {
        p.insert({v[r], r});
        if (r-l + 1 == k)
        {
            int mid = k/2;
            if (k%2 == 0) mid--;
            ans.push_back (p.find_by_order(mid)->first);
            p.erase ({v[l], l});
            l++;
        }
    }
    
    for (auto x : ans)
        cout << x << " ";
    cout << endl;
}