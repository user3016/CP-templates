int n,m; cin>>n>>m;
    int M = 20;
    int sp[n+1][m+1][M];

    memset(sp, 0, sizeof(sp));

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin >> sp[i][j][0];

    for(int k=1;k<M;k++) {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                int jmp = (1<<(k-1));
                if(i + jmp > n or j + jmp > m) {
                    continue;
                }
                sp[i][j][k] = gcd(
                                    gcd(sp[i][j][k-1],sp[i+jmp][j][k-1]),
                                    gcd(sp[i][j+jmp][k-1],sp[i+jmp][j+jmp][k-1])
                                    );
            }
        }
    }
    int x,y,l; cin>>x>>y>>l;
        int k = __lg(l);
        int jmp = l-(1<<k);
        long long ans = gcd(
                            gcd(sp[x][y][k], sp[x + jmp][y][k]),
                            gcd(sp[x][y + jmp][k], sp[x + jmp][y + jmp][k])
                            );
