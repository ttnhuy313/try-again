#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int f[N], g[N];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("SC2.INP", "r", stdin);
	freopen("SC2.OUT", "w", stdout);

	int tc;
	cin >> tc;
	for (int i = 1; i <= 1e5; ++i) {
		int d = i;
		while (d % 2 == 0 && d > 0) {
			f[i]++;
			d /= 2;
		}
		d = i;
		while (d % 5 == 0 && d) {
			g[i]++;
			d /= 5;
		}
		f[i] += f[i - 1];
		g[i] += g[i - 1];
	}
	while (tc--) {
		int n, k;
		cin >> n >> k;
		cerr << f[n] << endl;
		cout << min(f[n] - f[n - k] - f[k], g[n] - g[n - k] - g[k]) << endl;
	}

	return 0;
}