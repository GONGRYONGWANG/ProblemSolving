//#pragma warning(disable:4996) 
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define inf 1e9



int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    
    int N;
    cin >> N;
    vector<vector<int>> flower;
    int a, b, c, d;
    for (int i = 0; i < N; i++) {
        cin >> a >> b >> c >> d;
        flower.push_back({ a,b,c,d });
    }
    sort(flower.begin(), flower.end());
    int startm;
    int startd;
    int endm =3;
    int endd = 1;
    int idx = 0;
    vector<int> f = flower[idx];
    int sm, sd, em, ed;
    sm = f[0]; sd = f[1]; em = f[2]; ed = f[3];
    int ans = 0;
    while (idx<N && endm<12) {
        ans += 1;
        startm = endm;
        startd = endd;
        if (sm > startm || (sm == startm && sd > startd)) break;
        while (sm < startm || (sm == startm && sd <= startd)) {
            if (em > endm || (em == endm && ed > endd)) {
                endm = em;
                endd = ed;
            }
            idx++;
            if (idx == N) break;
            f = flower[idx];
            sm = f[0]; sd = f[1]; em = f[2]; ed = f[3];
        }
    }
    if (endm == 12) cout << ans;
    else cout << 0;
}
// #1086