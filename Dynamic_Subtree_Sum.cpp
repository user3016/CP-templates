void solve() {
    int n,q; cin >> n >> q;
    vector<int> v(n+1);
    for(int i = 1; i <= n; i++) cin >> v[i];
    vector<vector<int>> adj(n+1);
    for(int i = 2; i <= n; i++){
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> tour(n+1),start(n+1),end(n+1);
    int time = 0;
    function<void(int,int)> dfs = [&](int r, int p){
        time++;
        start[r] = time;
        tour[time] = r;
        for(int c : adj[r]){
            if(c == p) continue;
            dfs(c,r);
        }
        end[r] = time;
    };
    dfs(1,0);
    for(int i = 1; i <= n ;i++){
        tour[i] = v[tour[i]];
    }
    FenwickTree ft(tour);
    for(int qq= 0; qq < q; qq++){
        int op; cin >> op;
        if(op == 1){          // Operation 1 : update node 's' with value x
            int s,x; cin >> s >> x;
            ft.update(start[s],x-v[s]);
            v[s] = x;
        }
        else{                // Operation 2 : output sum of subtree of node 's' 
            int s; cin >> s;
            cout << ft.query(start[s],end[s]) << endl;
        }
    }
}
