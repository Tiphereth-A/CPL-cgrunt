int inv(int a, int mod) {
  int res = 1;
  for (int b = mod - 2; b; b >>= 1, (a *= a) %= mod)
    if (b & 1)
      (res *= a) %= mod;
  return res;
}

int v[N];

// a starts with 1
void inverse_multi2(int n, int p, const int *const a) {
  static int s[N];
  s[0] = 1;
  for (int i = 1; i <= n; ++i)
    s[i] = s[i - 1] * a[i] % p;
  v[n] = inv(s[n], p);
  for (int i = n; i >= 1; --i)
    v[i - 1] = v[i] * a[i] % p;
}
