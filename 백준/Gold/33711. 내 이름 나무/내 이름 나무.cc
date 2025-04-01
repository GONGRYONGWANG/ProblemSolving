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

vector<int> E[35001];

void solve(int tc) {

    int N, M, K;
    int W;
    cin >> N >> M >> K >> W;

    unordered_map<string, vector<int>> m;
    for (int i = 1; i <= W; i++) {
        int u; string name;
        cin >> u >> name;
        m[name].push_back(u);
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        E[a].push_back(b);
        E[b].push_back(a);
    }

    for (auto it = m.begin(); it != m.end(); it++) {
        vector<pii> visited(N + 1, { 0,0 });
        queue<int> q;
        for (int x : it->second) {
            visited[x] = { x,0 };
            q.push(x);
        }
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int nx : E[x]) {
                if (visited[nx].first == visited[x].first) continue;
                if (visited[nx].first != 0) {
                    if (visited[nx].second + visited[x].second + 1 <= K) {
                        cout << "POWERFUL CODING JungHwan";
                        return;
                    }
                    else continue;
                }
                visited[nx] = visited[x];
                visited[nx].second +=  1;
                q.push(nx);
            }


        }
    }

    cout << "so sad";





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