#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define endl "\n"
 
int R[300001];
 
void solve(int tc) {
 
    int Q;
    cin >> Q;
 
    set<pii> st;
    multiset<tuple<int,int,int>> mat;
    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, r;
            cin >> x >> r;
            R[x] = r;
            st.insert({ r,x });
            auto it = st.find({ r,x });
            if (it != st.begin() && next(it) != st.end()) {
                mat.erase({ next(it)->first - prev(it)->first, prev(it)->second, next(it)->second });
            }
            if (it != st.begin()) {
                mat.insert({ it->first - prev(it)->first, prev(it)->second, it->second });
            }
            if (next(it) != st.end()) {
                mat.insert({ next(it)->first - it->first, it->second, next(it)->second });
            }
        }
        else {
            auto [v, a, b] =  *mat.begin();
            mat.erase(mat.begin());
            cout << a << " " << b << endl;
            auto ait = st.find({ R[a],a });
            auto bit = st.find({ R[b],b });
            if (ait != st.begin() && next(bit) != st.end()) {
                mat.insert({ next(bit)->first - prev(ait)->first, prev(ait)->second, next(bit)->second });
            }
            if (ait != st.begin()) {
                mat.erase({ ait->first - prev(ait)->first, prev(ait)->second, ait->second });
            }
            if (next(bit) != st.end()) {
                mat.erase({ next(bit)->first - bit->first, bit->second, next(bit)->second });
            }
            st.erase(ait); st.erase(bit);
        }
 
    }
}
 
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }
 
    return 0;
}
