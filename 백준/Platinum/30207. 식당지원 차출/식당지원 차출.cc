// template: https://github.com/GONGRYONGWANG/ProblemSolving/blob/main/template.txt
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
#include<vector>
#include<array>
#include<utility>
#include<list>
#include<queue>
#include<stack>
#include<deque>
#include<tuple>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<cstdlib>
#include<ctime> // srand(time(0))
#include<regex> // 정규표현식
#include<random> // rand
#include<complex> // complex number
#include<numeric>
#include<cassert>
#include <climits>
#include <immintrin.h> // AVX, AVX2, AVX-512 // #pragma GCC optimize ("O3,unroll-loops") //#pragma GCC target ("avx,avx2,fma")
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef complex<double> cpx;
typedef long double ld;
#define pq priority_queue
#define endl "\n"
#define INF ll(4e18)
const int inf = 1e9 + 7;
const long double pi = 3.14159265358979323846;
const string debug = "output: ";
#define all(x) (x).begin(), (x).end()
#include<fstream>
ifstream fin; ofstream fout;

//int dx[4] = { -1,0,1,0 }; 
//int dy[4] = { 0,-1,0,1 }; 
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

struct cmp {
    bool operator()(pll& a, pll& b) {
        if (a.first == b.first) return a.second > b.second;
        return a.first > b.first;
    }
};

void solve(int tc) {

    ll N;
    cin >> N;

    ll total = 0;
    vector<ll> arr(N + 1, 0);
    pq<pll, vector<pll>, cmp> q;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        q.push({ arr[i],i });
        total += arr[i];
    }

    vector<ll> init = arr;

    int Q;
    cin >> Q;

    if (N == 3) {
        while (Q--) {
            ll d, x;
            cin >> d >> x;
            cout << d << endl;
        }
        return;
    }

    

    
    vector<vector<ll>> query(Q);
    vector<ll> ret(Q);

    for (int i = 0; i < Q; i++) {
        ll d, x;
        cin >> d >> x;
        query[i] = { d,x,i };
    }
    sort(query.begin(), query.end());

    int qidx = 0;
    ll cur = 0;

    while (cur <= 1000000) { 
        cur += 1;
        vector<int> tmp(3);
        for (int i = 0; i < 3; i++) tmp[i] = q.top().second, q.pop();
        for (int i = 0; i < 3; i++) arr[tmp[i]] += 1;
        for (int i = 0; i < 3; i++) q.push({ arr[tmp[i]], tmp[i] });
        while (qidx != Q && query[qidx][0] == cur) ret[query[qidx][2]] = arr[query[qidx][1]] - init[query[qidx][1]], qidx += 1;
    }


    while (qidx != Q) {
        ll d = query[qidx][0]; ll x = query[qidx][1];
        int idx = query[qidx][2];
        ret[idx] = (total + 3 * d) / N - init[x];
        if ((total + 3 * d) % N >= x) ret[idx] += 1;
        qidx += 1;
    }

    for (ll ans : ret) cout << ans << endl;



}
    



int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    //fin.open("input.txt"); fout.open("output.txt");
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}