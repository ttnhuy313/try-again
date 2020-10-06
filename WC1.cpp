#include <bits/stdc++.h>

using namespace std;
#define int unsigned long long

const int N = 1e5 + 5, MOD = 68718952446;
int a[N], n, pre[N], suf[N];

void mul(int &a, int b) {
	a = a * b % MOD;
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	pre[0] = 1; suf[n + 1] = 1;
	for (int i = 1; i <= n; ++i) {
		pre[i] = pre[i - 1];
		mul(pre[i], a[i]);
	}
	for (int i = n; i >= 1; --i) {
		suf[i] = suf[i + 1];
		mul(suf[i], a[i]);
	}
	for (int i = 1; i <= n; ++i) {
		cout << (pre[i- 1] * suf[i + 1]) % MOD << ' ';
	}
	cout << endl;

}

main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("WC1.INP", "r", stdin);
	freopen("WC1.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}