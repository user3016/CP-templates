vector<int> adj[N];
vector<int> bfs(int st) {
    vector<int> dist(N, INF);
    queue<int> q;
    dist[st] = 0;
    q.push(st);
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (auto ch : adj[v]) {
            if (dist[ch] > dist[v]+1) {
                dist[ch] = dist[v]+1;
                q.push(ch);
            }
        }
    }
    return dist;
}
