struct DSU {
    vector<int> parent, sz;

    DSU(int n) {
        parent.resize(n + 1);
        sz.resize(n + 1, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        int ans = x;
        while (ans != parent[ans])
            ans = parent[ans];
        while (x != ans) {
            int nxt = parent[x];
            parent[x] = ans;
            x = nxt;
        }
        return ans;
    }

    void connect(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b)
            return;
        if (sz[a] > sz[b])
            swap(a, b);
        parent[a] = b;
        sz[b] += sz[a];
    }
};
