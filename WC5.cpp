 #include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1005, oo = 1e9;
int cost[N][N], n, m, dp[N][N][2];

void solve() {
	memset(cost, 0, sizeof cost);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> cost[i][j];
			dp[i][j][0] = dp[i][j][1] = oo;
		}
	}
	for (int i = 0; i <= n; ++i) for (int j = 0; j <= m; ++j) dp[i][j][0] = dp[i][j][1] = oo;
	dp[1][0][0] = 0;
	dp[0][1][1] = 0;
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			if (i + j <= 1) continue;
			for (int k = 0; k < 2; ++k) {
				if (i == 0 && k == 0) continue;
				if (j == 0 && k == 1)continue;
				if (k == 0) {
					if (i > 1) dp[i][j][k] = dp[i - 1][j][0];
					if (j) dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][1] + cost[i][j]);
				} else {
					if (i) dp[i][j][k] = dp[i][j - 1][0] + cost[i][j];
					if (j > 1) dp[i][j][k] = min(dp[i][j][k], dp[i][j - 1][1]);
				}
			}
		}
	}
	cout << min(dp[n][m][0], dp[n][m][1]) << endl;
}

main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("WC5.INP", "r", stdin);
	freopen("WC5.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}