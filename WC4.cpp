#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2e3 + 5, MOD = 1e9 + 7;
int fac[N], dp[N][N];

main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("WC4.INP", "r", stdin);
	freopen("WC4.OUT", "w", stdout);


	dp[0][0] = 1;
	for (int i = 1; i <= N - 1; ++i) {
		for (int j = 1; j <= i; ++j) {
			dp[i][j] += 1LL * dp[i - 1][j] * j % MOD;
			dp[i][j] %= MOD;
			dp[i][j] += dp[i - 1][j - 1];
			dp[i][j] %= MOD;
		}
	}
	
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		int res = 0;
		for (int i = 1; i <= n; ++i) {
			int tmp = dp[n][i];
			res = (res + tmp) % MOD;
			//cerr << "Seperate to " << i << " parts : " << tmp << endl;
		}
		cout << res << endl;
	}

	return 0;
}