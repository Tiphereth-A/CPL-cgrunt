#include <bits/stdc++.h>
using namespace std;
using pii = pair<long long, long long>;

#define _for(i, l, r, vals...) for (int i = (l), ##vals; i <= (r); ++i)
#define _rfor(i, r, l, vals...) for (int i = (r), ##vals; i >= (l); --i)

const int MOD = 1e9 + 7;
long long inverse(long long a, long long b = MOD - 2, long long mod = MOD) {
  long long res = 1;
  for (; b; b >>= 1, (a *= a) %= mod) if (b & 1) (res *= a) %= mod;
  return res;
}

const int N = 2e5 + 5;

long long x[N], y[N], z[N];
long long mx[N] = {1}, inv[N];
pii coeff[N];
long long ans[N];

pii operator*(const pii &lhs, long long rhs) {
  pii ret(lhs);
  (ret.first *= rhs) %= MOD;
  (ret.second *= rhs) %= MOD;
  return ret;
}
pii operator+(const pii &lhs, const pii &rhs) {
  return pii((lhs.first + rhs.first) % MOD, (lhs.second + rhs.second) % MOD);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int _t;
  cin >> _t;
  while (_t--){
    int n;
    cin >> n;
    _for(i, 1, n) cin >> x[i] >> y[i] >> z[i];
    _for(i, 1, n) mx[i] = mx[i - 1] * x[i] % MOD;
    inv[n] = inverse(mx[n]);
    _rfor(i, n, 1) inv[i - 1] = inv[i] * x[i] % MOD;
    _for(i, 1, n) (inv[i] *= mx[i - 1]) %= MOD;
    _for(i, 1, n) coeff[i] = {MOD - y[i], z[i]};
    coeff[1] = coeff[1] * inv[1];
    _for(i, 2, n) coeff[i] = (coeff[i - 1] * y[i] + coeff[i]) * inv[i];
    if (coeff[n].first == 1) {
      cout << (coeff[n].second ? 0 : MOD) << '\n';
      return;
    }
    ans[n] = coeff[n].second * inverse(MOD + 1 - coeff[n].first) % MOD;
    _for(i, 1, n - 1) ans[i] = (coeff[i].second + coeff[i].first * ans[n] % MOD) % MOD;
    cout << "1\n";
    _for(i, 1, n) cout << (ans[i] - ans[i - 1] + MOD) % MOD << " \n"[i == n];
  }
  return 0;
}
