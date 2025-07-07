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

vector<int> E[100001];
bool visited[100001];

int cnt;

bool isleaf(int x, int p) {
    if (visited[x]) return false;
    visited[x] = true;
    return (E[x].size() == 1);
}

bool isstalk(int x, int p) {
    if (visited[x]) return false;
    cnt += 1;
    visited[x] = true;
    if (E[x].size() == 1) return true;
    if (E[x].size() != 2 && E[x].size() != 3 && E[x].size() != 4) return false;

    if (E[x].size() == 2) {
        for (int nx : E[x]) {
            if (nx == p) continue;
            if (!isstalk(nx, x)) return false;
        }
        return true;
    }
    else if (E[x].size() == 3) {
        for (int nx : E[x]) {
            if (nx == p) continue;
            if (!isleaf(nx, x)) return false;
        }
        return true;
    }
    else { // E[x].size()==4
        vector<pii> v;
        for (int nx : E[x]) {
            if (nx == p) continue;
            v.push_back({ E[nx].size(),nx });
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < 2; i++) {
            if (!isleaf(v[i].second, x)) return false;
        }
        for (int i = 2; i < v.size(); i++) {
            if (!isstalk(v[i].second, x)) return false;
        }
        return true;
    }
}



void solve(int tc) {

    int N, M;
    cin >> N >> M;

    while (M--) {
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        if (visited[i]) continue;
        if (E[i].size() != 2 && E[i].size() != 4) continue; // indegree==2or4 -> middle stalk
        cnt = 0;
        if (!isstalk(i, 0)) {
            cout << "NIE";
            return;
        }
        if (cnt < 4) {
            cout << "NIE";
            return;
        }
    }

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            cout << "NIE";
            return;
        }
    }

    cout << "TAK";


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