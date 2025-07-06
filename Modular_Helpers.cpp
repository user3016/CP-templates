int mul(int a, int b) {
    return ((a % mod) * (b % mod)) % mod;
}

int sub(int a, int b) {
    return (a - b + mod) % mod;
}

int add(int a, int b) {
    return (a + b) % mod;
}
