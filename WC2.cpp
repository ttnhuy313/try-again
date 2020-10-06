#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("WC2.INP", "r", stdin);
	freopen("WC2.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; ++i) cout << i << ' ' << i << endl;
		for (int i = 1; i <= 10; ++i) cout <<"#";
		cout << endl;
	}

	return 0;
}