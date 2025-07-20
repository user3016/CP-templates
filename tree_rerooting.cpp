int n;
vector<int> total(N, 0), sz(N);
vector<vector<pii>> adj(N);

int dfs1(int v, int p) {
    sz[v] = 1;
    for (auto [ch,w] : adj[v]) {
        if (ch != p) {
            dfs1(ch,v);
            sz[v] += sz[ch];
            total[v] += total[ch]+sz[ch]*w;
        }
    }
}

void dfs2(int v, int p) {
    for (auto [ch,w] : adj[v]) {
        if (ch != p) {
            total[ch] = total[v]-(sz[ch]*w)+(n-sz[ch])*w;
            dfs2(ch,v);
        }
    }  
}

void solve() {
    cin >> n;
    for (int i = 0; i < n-1; ++i) {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    dfs1(1,1);
    dfs2(1,1);
    for (int i = 1; i <= n; i++) cout << total[i] << ' ';
}
