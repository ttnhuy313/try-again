#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> ii;
#define int long long

struct DisjointSet {
	int n, cSize;
	vector <int> lab, Rank;
	DisjointSet() {}
	DisjointSet(int _n) {
		this -> n = _n;
		this -> cSize = n;
		lab.assign(n + 5, -1);
		Rank.assign(n + 5, 1);
	}

	int root(int x) {
		return (lab[x] == -1 ? x : lab[x] = root(lab[x]));
	}

	bool merge(int u, int v) {
		int x = root(u), y = root(v);
		if (x == y) return false;
		if (Rank[x] < Rank[y]) swap(x, y);
		lab[y] = x;
		Rank[x] += Rank[y];
		cSize--;
		return true;
	}
} DSU;

const int N = 1e5 + 5;
int n, res;
vector <ii> adj[N];

void dfs(int u, int pre) {
	for (int k = 0; k < adj[u].size(); ++k) {
		int v = adj[u][k].first;
		bool type = adj[u][k].second;
		if (v == pre) continue;
		if (type == 0) {
			if (DSU.merge(u, v)) res += DSU.Rank[DSU.root(u)] - 1;
		}
		dfs(v, u);
	}
}

void solve() {
	cin >> n;
	res = 0;
	for (int i = 1; i <= n; ++i) adj[i].clear();
	for (int i = 1; i <= n - 1; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(ii(v, w));
		adj[v].push_back(ii(u, w));
	}
	DSU = DisjointSet(n);
	dfs(1, -1);
	cout << n * (n - 1) / 2 - res << endl;
}

main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("WC3.INP", "r", stdin);
	freopen("WC3.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}