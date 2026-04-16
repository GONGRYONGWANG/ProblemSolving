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

pll pt[100000];

ll ccw(pll a, pll b, pll c) {
    return (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first);
}

bool cmpy(pll a, pll b){
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

bool cmpc(pll a, pll b) {
    ll cc = ccw(pt[0], a, b);
    if (cc != 0) return cc > 0;
    else if (a.second != b.second) return a.second < b.second;
    return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> pt[i].first >> pt[i].second;
    }
    sort(pt, pt + N, cmpy);
    sort(pt + 1, pt + N, cmpc);
    stack<pll> s;
    s.push(pt[0]);
    s.push(pt[1]);

    pll ff, ss;
    for (int i = 2; i < N; i++) {
        while (s.size() >= 2) {
            ss = s.top();
            s.pop();
            ff = s.top();
            if (ccw(ff, ss, pt[i]) > 0) {
                s.push(ss);
                break;
            }
        }
        s.push(pt[i]);
    }
    cout << s.size();
    return 0;
}
