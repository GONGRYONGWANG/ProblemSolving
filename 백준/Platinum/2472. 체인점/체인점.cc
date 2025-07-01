// template: https://github.com/GONGRYONGWANG/ProblemSolving/blob/main/template.txt
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
#include<cctype>
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
const int inf = 1000000007;
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
    bool operator()(pii& a, pii& b) {
        return a.second > b.second;
    }
};

vector<pii> E[100001];
int distA[100001], distB[100001], distC[100001];


bool ret[100001];

void solve(int tc) {


    int N;
    cin >> N;

    int A, B, C;
    cin >> A >> B >> C;

    int M;
    cin >> M;
    while (M--) {
        int u, v, w;
        cin >> u >> v >> w;
        E[u].push_back({ v,w });
        E[v].push_back({ u,w });
    }

    pq<pii, vector<pii>, cmp> q;

    q.push({ A,1 });
    while (!q.empty()) {
        auto [x, d] = q.top();
        q.pop();
        if (distA[x]) continue;
        distA[x] = d;
        for (pii& e : E[x]) {
            if (distA[e.first]) continue;
            q.push({ e.first,e.second + d });
        }
    }

    q.push({ B,1 });
    while (!q.empty()) {
        auto [x, d] = q.top();
        q.pop();
        if (distB[x]) continue;
        distB[x] = d;
        for (pii& e : E[x]) {
            if (distB[e.first]) continue;
            q.push({ e.first,e.second + d });
        }
    }

    q.push({ C,1 });
    while (!q.empty()) {
        auto [x, d] = q.top();
        q.pop();
        if (distC[x]) continue;
        distC[x] = d;
        for (pii& e : E[x]) {
            if (distC[e.first]) continue;
            q.push({ e.first,e.second + d });
        }
    }

    vector<pii> arr;
    for (int i = 1; i <= N; i++) {
        arr.push_back({ distA[i], i });
    }

    sort(arr.begin(), arr.end());

    int lidx = 0;

    map<int, int> m;
    for (int i = 0; i < N; i++) {
        int idx = arr[i].second;

        auto iter = m.lower_bound(distB[idx]);
        if (iter == m.begin()) ret[idx] = true;
        else {
            iter = prev(iter);
            if (iter->second <= distC[idx]) ret[idx] = false;
            else ret[idx] = true;
        }

        if (i != N - 1 && arr[i].first != arr[i + 1].first) {
            while (lidx != i + 1) {
                
                int pos = arr[lidx].second;
                if (!m.count(distB[pos])) m[distB[pos]] = inf;
                m[distB[pos]] = min(distC[pos], m[distB[pos]]);
                auto it = m.find(distB[pos]);
                while (next(it) != m.end() && next(it)->second >= it->second) m.erase(next(it));
                if (it != m.begin() && prev(it)->second <= it->second) m.erase(it);

                lidx += 1;
            }
        }
    }

    int T;
    cin >> T;
    while (T--) {
        int x;
        cin >> x;
        cout << (ret[x] ? "YES" : "NO") << endl;
    }



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