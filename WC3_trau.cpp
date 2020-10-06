#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> ii;

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

const int N = 1e3 + 5;
int n, res;
vector <ii> adj[N];
bool mark[N];

void dfs(int u, int pre) {
	mark[u] = 1;
	for (int k = 0; k < adj[u].size(); ++k) {
		int v = adj[u][k].first;
		bool type = adj[u][k].second;
		if (v == pre) continue;
		if (type == 0) dfs(v, u);
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
	for (int i = 1; i <= n; ++i) {
		memset(mark, 0, sizeof mark);
		dfs(i, -1);
		for (int j = i + 1; j <= n; ++j) if (!mark[j]) res++;
	}
	cout << res << endl;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("WC3.INP", "r", stdin);
	freopen("WC3.ANS", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}