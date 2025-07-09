struct sqrt_decomp{
	vector<int> a, block_sum;
	int B;
	int n;
	sqrt_decomp(int n){ // 1-based sqrt decomp
		this->n = n;
		B = ceil(sqrt(n));
		a.resize(B*B+1);
		block_sum.resize(B+1);
	}
	void build(){ // call after inputing values to array a
		for(int i = 1; i <= n; i++){
			block_sum[get_block(i)] += a[i];
		}
	}
	int get_block(int i){
		return (i+B-1)/B;
	}
	int op1(int i){ // remove a[i] -> a[i] = 0 and return removed value
		int val = a[i];
		a[i] = 0;
		block_sum[get_block(i)] -= val;
		return val;
	}
	void op2(int i, int v){ // add v to a[i]
		a[i] += v;
		block_sum[get_block(i)] += v;
	}
	int sum(int l, int r){ // return sum a[l...r] 1-based inclusive
		int start = get_block(l), end = get_block(r), sum = 0;
		if(start == end){
			for(int i = l; i <= r; i++) sum += a[i];
		}
		else{
			for(int i = l; i <= start*B; i++) sum += a[i];
			for(int i = r; i > (end-1)*B; i--) sum += a[i];
			for(int block = start+1; block < end; block++) sum += block_sum[block];			
		}
		return sum;
	}
};
