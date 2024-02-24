#pragma warning(disable:4996) 
#include<iostream>
#include<vector>
#include<list>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<deque>
#include<utility>
#include<string>
#include<map>
#include<set>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define pq priority_queue
typedef unsigned long long ull;
typedef unsigned int uint;
//int dx[4] = { 1,-1,0,0 };
//int dy[4] = { 0,0,1,-1 };
//int dx[8] = { 1,1,1,-1,-1,-1,0,0 };
//int dy[8] = { 1,0,-1,1,0,-1,1,-1 };
#define inf 1e9

ll P, B, N;

ll fastpow(ll a, ll b) {
    if (b == 0) return 1;
    if (b % 2) return fastpow(a, b - 1) * a % P;
    ll half = fastpow(a, b / 2);
    return half * half % P;
}

void solve() {
    ll M = ceil(sqrt(P));
    unordered_map<ll, ll> m;

    ll val = 1;
    for (ll i = 0; i < M; i++) {
        if (m.find(val)!=m.end()) {
            m[val] = min(m[val], i);
        }
        else m[val] = i;
        val = val * B % P;
    }

    val = 1;
    for (int i = 0; i < M; i++) {
        if (m.find(N * val % P)!=m.end()) {
            cout << i * M + m[N * val % P]<<endl;
            return;
        }
        val *= fastpow(fastpow(B, M), P - 2); // (B^M)^(P-2) = (B^M)^(-1) 페르마 소정리
        val %= P;
    }
    cout << "no solution" << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    while (1) {
        cin >> P >> B >> N;
        if (cin.eof()) break;
        solve();
    }
    return 0;
}

// 참고: https://platter.tistory.com/8