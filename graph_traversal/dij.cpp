vector<pii> adj[N];
vector<int> dij(int st) {
    vector<int> dist(N, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[st] = 0;
    pq.push({0,st});
    while (!pq.empty()) {
        auto [d, v] = pq.top(); pq.pop();
        if (d != dist[v]) continue;
        for (auto [ch, w] : adj[v]) {
            if (dist[ch] > dist[v]+w) {
                dist[ch] = dist[v]+w;
                pq.push({dist[ch], ch});
            }
        }
    }
    return dist;
}
