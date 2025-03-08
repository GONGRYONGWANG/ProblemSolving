// template: https://github.com/GONGRYONGWANG/ProblemSolving/blob/main/template.txt
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
#include<vector>
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
const ll INF = 1e18 + 7;
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

vector<pll> xE[200002];
vector<pll> yE[200002];
bool visited[200002][2];

struct cmp {
    bool operator()(vector<ll>& a, vector<ll>& b) {
        return a[2] > b[2];
    }
};

void solve(int tc) {

    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<pii>> xarr(N + 1);
    vector<vector<pii>> yarr(M + 1);
    xarr[1].push_back({ 1,0 });
    yarr[1].push_back({ 1,0 });
    xarr[N].push_back({ M,K + 1 });
    yarr[M].push_back({ N,K + 1 });
    for (int i = 1; i <= K; i++) {
        int x, y;
        cin >> x >> y;
        xarr[x].push_back({ y,i });
        yarr[y].push_back({ x,i });
    }

    for (int i = 1; i <= N; i++) {
        if (xarr[i].size() <= 1) continue;
        sort(xarr[i].begin(), xarr[i].end());
        for (auto it = xarr[i].begin(); next(it) != xarr[i].end(); it++) {
            auto nit = next(it);
            xE[it->second].push_back({ nit->second, nit->first - it->first });
            xE[nit->second].push_back({ it->second, nit->first - it->first });
        }
    }
    for (int i = 1; i <= M; i++) {
        if (yarr[i].size() <= 1) continue;
        sort(yarr[i].begin(), yarr[i].end());
        for (auto it = yarr[i].begin(); next(it) != yarr[i].end(); it++) {
            auto nit = next(it);
            yE[it->second].push_back({ nit->second, nit->first - it->first });
            yE[nit->second].push_back({ it->second, nit->first - it->first });
        }
    }

    pq<vector<ll>, vector<vector<ll>>, cmp> q;
    q.push({ 0,0,0 });
    while (!q.empty()) {
        int x = q.top()[0];
        bool b = q.top()[1];
        ll d = q.top()[2];
        q.pop();
        if (visited[x][b]) continue;
        visited[x][b] = true;
        if (x == K + 1) {
            cout << d;
            return;
        }
        if (x != 0 && !visited[x][!b]) {
            q.push({ x,!b,d + 1 });
        }
        if (!b) {
            for (pll& e : xE[x]) {
                int nx = e.first;
                if (visited[nx][b]) continue;
                q.push({ nx,b,d + e.second });
            }
        }
        else {
            for (pll& e : yE[x]) {
                int nx = e.first;
                if (visited[nx][b]) continue;
                q.push({ nx,b,d + e.second });
            }
        }
    }

    cout << -1;
    





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