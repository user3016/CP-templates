#include <bits/stdc++.h>
using namespace std;
#define int long long
const unsigned int N = 1e6;
const int mod = 1e9+7;

int fact[N+5], inv[N+5];

int mult(int a, int b) {
    return (a % mod * b % mod) % mod;
}

int add(int a, int b) {
    return (a % mod + b % mod) % mod;
}

int fastpw(int a, int b) {
    if (b == 0) return 1;
    int ans = 1;
    while (b) {
        if (b&1) ans = mult(ans, a);
        a = mult(a,a);
        b /= 2;
    }
    return ans;
}


int nCr(int n, int r) {
    if (n < r) return 0;
    return mult(fact[n], mult(inv[r], inv[n-r]));
}

signed main() {
    fact[0] = 1;
    for (int i = 1; i <= N; i++) {
        fact[i] = mult(i, fact[i-1]);
    }

    inv[N] = fastpw(fact[N], mod-2);
    for (int i = N-1; i >= 0; i--) {
        inv[i] = mult(inv[i+1], i+1);
    }
    return 0;
}
