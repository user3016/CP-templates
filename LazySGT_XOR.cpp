struct lazy_segment_tree {
    vector<array<int,32>> sum; vector<int> lazy;
    int n;
    int size = 1;
    void merge(int x, int l,int r) {
        int m = (l + r) / 2;
        if(lazy[L(x)])
            apply(L(x), l, m);
        if(lazy[R(x)])
            apply(R(x), m + 1, r);
        for(int bit = 0; bit < 32; bit++) {
            sum[x][bit] = sum[L(x)][bit] + sum[R(x)][bit];
        }
    }
    void build(int x, int l, int r) {
        if(l == r)
            return;
        int m = (l + r) / 2;
        build(L(x), l, m);
        build(R(x), m + 1, r);
        merge(x, l, r);
    }
    lazy_segment_tree(int n, const vector<int>& v) {
        this->n = n;
        while(size <= n)
            size *= 2;
        lazy.resize(2*size+1);
        sum.resize(2*size+1);
        for(int i = size; i <= size+n-1; i++) {
            for(int bit = 0; bit < 32; bit++) {
                if((v[i-size+1]>>bit)&1) {
                    sum[i][bit]++;
                }
            }
        }
        build(1, 1, size);
    }
    int L(int x) {
        return 2*x;
    }
    int R(int x) {
        return L(x)+1;
    }
    void push(int x) {
        lazy[L(x)] ^= lazy[x];
        lazy[R(x)] ^= lazy[x];
        lazy[x] = 0;
    }
    void apply(int x, int l, int r) {
        int len = r - l + 1;
        for(int bit = 0; bit < 32; bit++) {
            if(lazy[x] & (1 << bit)) {
                sum[x][bit] = len - sum[x][bit];
            }
        }
        if (l != r) {
            lazy[L(x)] ^= lazy[x];
            lazy[R(x)] ^= lazy[x];
        }
        lazy[x] = 0;
    }
    void update(int x, int l, int r, int lx, int rx, int v) {
        if(l > rx or r < lx) return;
        if(lazy[x]) apply(x, l, r);
        if(l >= lx and r <= rx) {
            lazy[x] ^= v;
            apply(x, l, r);
            return;
        }
        int m = (l + r) / 2;
        update(L(x), l, m, lx, rx, v);
        update(R(x), m + 1, r, lx, rx, v);
        merge(x,l,r);
    }
    void update(int l, int r, int v) {
        update(1, 1, size, l, r, v);
    }
    int get_node_sum(int x) {
        int s = 0;
        for(int bit = 0; bit <= 31; bit++) {
            s += (1<<bit)*sum[x][bit];
        }
        return s;
    }
    int query(int x, int l, int r, int lx, int rx) {
        if(l > rx or r < lx) return 0;
        if(lazy[x])
            apply(x,l,r);
        if(l >= lx and r <= rx) {
            return get_node_sum(x);
        }
        int m = (l + r) / 2;
        return query(L(x),l,m,lx,rx) + query(R(x),m+1,r,lx,rx);
    }
    int query(int l, int r) {
        return query(1, 1, size, l, r);
    }
};
