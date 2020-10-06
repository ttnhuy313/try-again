#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;
map <int, int> cnt;
int a[N], n;

void solve() {
	cin >> n;
	cnt.clear();
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 2; i <= n; ++i) a[i] += a[i - 1];
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) if (a[i] == a[j] - a[i] && a[i] == a[n] - a[j]) res++;
	}
	cout << res << endl;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("WC6.INP", "r", stdin);
	freopen("WC6.ANS", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}