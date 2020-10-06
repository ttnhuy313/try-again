#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("SC1.inp","r",stdin);
    freopen("SC1.out","w",stdout);

    int p10[] = {(int)1e6, (int)1e5, (int)1e5, (int)1e5, (int)1e5, (int)1e4, (int)1e4, (int)1e3, (int)1e2};
    int tc, a, b;
    cin >> tc;
    while(tc--) {
        string s, ans;
        int fl = 0;
        cin >> a;
        for(int i = 0; i < 9; i++) {
            cin >> s >> b;
            if(a % p10[i] == b && !fl) {
                ans = s; 
                fl = 1;
            }
        }
        if(fl) for (int i = 0; i < ans.size() - 1; ++i) cout << ans[i];
        else cout << "NONE";
        cout << '\n';
    }
}