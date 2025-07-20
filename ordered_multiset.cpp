#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define pii pair<int,int>

struct cmp {
    bool operator()(const pii &a, const pii &b) const {
        if (a.first != b.first) return a.first < b.first;
        return a.second < b.second;
    }
};
using ordered_multiset = tree<pii, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    ordered_multiset oms;
    int n; cin >> n;
    int id = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        oms.insert({x,id++});
    }
}
