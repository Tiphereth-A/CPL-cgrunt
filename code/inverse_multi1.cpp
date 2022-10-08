int inv[N];
void inverse_multi1(int n, int p) {
  inv[1] = 1;
  for (int i = 2; i <= n; ++i)
    inv[i] = (p - p / i) * inv[p % i] % p;
}
