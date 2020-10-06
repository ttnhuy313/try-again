#include <bits/stdc++.h>

using namespace std;

struct Node {
	bool tag;
	int val;
};

struct SegmentTree {
	vector <Node> st;
	int n;
	SegmentTree() {}
	SegmentTree(int _n) {
		this -> n = _n;
		st.assign(4 * n + 5, {0, 0});
	}
	int Left(int x) {return (x << 1);}
	int Right(int x) {return (x << 1) + 1;}
	void push(int id) {
		if (st[id].tag) {
			st[Left(id)].val = st[id].val;
			st[Left(id)].tag = true;
			st[Right(id)].val = st[id].val;
			st[Right(id)].tag = true;
		}
		st[id].tag = false;
	}
	void update(int id, int L, int R, int i, int j, int val) {
		if (L > j || R < i) return;
		if (L >= i && R <= j) {
			st[id].val = val;
			st[id].tag = true;
			return;
		}
		int mid = (L + R) >> 1;
		push(id);
		update(Left(id), L, mid, i, j, val);
		update(Right(id), mid + 1, R, i, j, val);
	}
	int get(int id, int L, int R, int i) {
		if (L <= i && R >= i && st[id].tag) {
			return st[id].val;
		}
		int mid = (L + R) >> 1;
		if (i <= mid) return get(Left(id), L, mid, i);
		else return get(Right(id), mid + 1, R, i);
	}

	int query(int x) {return get(1, 1, n, x);}
	void update(int i, int j, int val) {update(1, 1, n, i, j, val);}
};

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("SM3.INP", "r", stdin);
	freopen("SM3.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		SegmentTree solver(m);
		solver.update(1, m, 0);
		set <int> avail; avail.clear();
		for (int i = 1; i <= n; ++i) {	
			int l, r;
			cin >> l >> r;
			solver.update(l, r, i);
		}
		for (int i = 1; i <= m; ++i) {
			avail.insert(solver.query(i));
		}
		cout << (int)avail.size() - (avail.find(0) != avail.end() ? 1 : 0) << endl;
	}

	return 0;
}