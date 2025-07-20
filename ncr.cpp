int nCr (int n, int r) {
    long double ans = 1;
    for (int i = 1; i <= r; i++) {
        ans = ans*(n-r+i)/i;
    }
    return (int)(ceil(ans));
};
// nCr in O(r)
