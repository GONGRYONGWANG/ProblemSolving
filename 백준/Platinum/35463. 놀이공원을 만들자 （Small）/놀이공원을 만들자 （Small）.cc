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
#include<complex> // complex number
#include<numeric>
#include<cassert>
#include <climits>
#include <immintrin.h> // AVX, AVX2, AVX-512 // #pragma GCC optimize ("O3,unroll-loops") //#pragma GCC target ("avx,avx2,fma")
#include<chrono>
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
#define INF ll(2e18)
const int inf = 1000000007;
const long double pi = acosl(-1);
const string debug = "debug: ";
#define all(x) (x).begin(), (x).end()

#include<random> // rand
std::mt19937 gen;
void rng_init() {
    std::random_device rd;
    gen.seed(rd());  // main에서 1번
}
int randint(int l, int r) {
    std::uniform_int_distribution<int> dist(l, r);
    return dist(gen);
}

#include<fstream>
ifstream fin; ofstream fout;

//#define cin fin 
//#define cout fout

//int dx[4] = { -1,0,1,0 };
//int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////

vector<pii> E[101];
int T[101], P[101];
int DP[101][101];
bool isend[101];

struct cmp {
    bool operator()(vector<int>& a, vector<int>& b) {
        return a[2] > b[2];
    }
};

struct cmp2 {
    bool operator()(pii& a, pii& b) {
        return a.second > b.second;
    }
};

void solve(int tc) {

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> T[i] >> P[i];
    }
    
    vector<int> s = { 1 }, e = { 1 };
    for (int i = 2; i <= N; i++) {
        if (P[i] < P[s.front()]) s = { i };
        else if (P[i] == P[s.front()]) s.push_back(i);
        if (P[i] > P[e.front()]) e = { i };
        else if (P[i] == P[e.front()]) e.push_back(i);
    }

    vector<int> S(M);
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        S[i] = w;
        E[u].push_back({ v,w });
    }

    sort(S.begin(), S.end());

    pq<vector<int>, vector<vector<int>>, cmp> q;
    for (int x : s) {
        q.push({ x,0,T[x] + P[x] });
    }

    for (int x : e) isend[x] = true;

    int ret = -1;
    {
        vector<bool> visited(N + 1, false);
        pq<pii, vector<pii>, cmp2> q2;
        for (int x : s) {
            q2.push({ x,T[x] + P[x] });
        }
        while (!q2.empty()) {
            auto [x, d] = q2.top();
            q2.pop();
            if (visited[x]) continue;
            if (isend[x]) {
                ret = d;
                break;
            }
            visited[x] = true;
            for (auto& [nx, w] : E[x]) {
                if (visited[nx]) continue;
                q2.push({ nx,w + d + T[nx] + P[nx] });
            }
        }

        if (ret == -1) {
            cout << -1;
            return;
        }
    }



    while (!q.empty()) {
        int x = q.top()[0];
        int n = q.top()[1];
        int d = q.top()[2];
        q.pop();
        if (isend[x]) {
            cout << ret - d;
            return;
        }
        if (DP[x][n]) continue;
        DP[x][n] = d;
        if (n == N - 1 || n == M) continue;
        for (auto& [nx, w] : E[x]) {
            if (DP[nx][n + 1]) continue;
            q.push({ nx,n + 1,d + T[nx] + P[nx] + S[n] });
        }
    }




    // cout << "Case #" << tc << ": " << ret << endl;
}


int main() {
    //fin.open("input.txt"); fout.open("output.txt");
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    rng_init();
    int T = 1;
    //cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}