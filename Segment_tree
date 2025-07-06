struct segment_tree
{
	int size = 1;
	vector<int> arr;
	int Zero = 0;
	segment_tree(int n)
	{
		while(size < n)
			size *= 2;
		arr.resize(2*size+1);
	}
	void build(int x, int l, int r)
	{
		if(l == r)
			return;
		int m = (l+r)/2;
		build(L(x),l,m);
		build(R(x),m+1,r);
		arr[x] = merge(arr[L(x)],arr[R(x)]);
	}
	segment_tree(int n, vector<int> a)
	{
		while(size < n)
		size *= 2;
		arr.resize(2*size+1);
		for(int i = size; i <= size+n-1; i++)
		{
			arr[i] = a[i-size+1];
		}
		build(1,1,size);
	}
	int L(int x)
	{
		return 2*x;
	}
	int R(int x)
	{
		return 2*x+1;
	}
	int merge(int a, int b)
	{
		return a+b;
	}
	void update(int i, int v,int x, int l, int r)
	{
		if(l == r)
		{
			arr[x] = v;
			return;
		}
		int m = (r+l)/2;
		if(i <= m)
			update(i,v,L(x),l,m);
		else
			update(i,v,R(x),m+1,r);
		arr[x] = merge(arr[L(x)],arr[R(x)]);
	}
	void update(int i, int v)
	{
		update(i,v,1,1,size);
	}
	int query(int x, int l, int r, int lx, int rx)
	{
		if(l > rx or r < lx) return Zero; 
		if(l >= lx and r <= rx) return arr[x];
		int m = (r+l)/2;
		return merge(query(L(x),l,m,lx,rx),query(R(x),m+1,r,lx,rx));
	}
	int query(int l, int r)
	{
		return query(1,1,size,l,r);
	}
};
