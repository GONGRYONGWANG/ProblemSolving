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
const long double pi = 3.14159265358979323846;
const string debug = "debug: ";
#define all(x) (x).begin(), (x).end()
#include<fstream>
ifstream fin; ofstream fout;


//int dx[4] = { -1,0,1,0 };
//int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////




void solve(int tc) {

    while (1) {
        int N;
        cin >> N;
        if (N == 0) break;
        unordered_map<string, int> deg;
        unordered_map<string, string> parent;
        unordered_map<string, vector<string>> child;
        string root;
        cin >> root;
        deg[root] = 0;
        for (int i = 0; i < N - 1; i++) {
            string c, p;
            cin >> c >> p;
            deg[p] += 1;
            deg[c] += 0;
            parent[c] = p;
            child[p].push_back(c);
        }

        queue<string> q;
        vector<unordered_map<string, pii>> DP(2);

        for (auto it = deg.begin(); it != deg.end(); it++) {
            if (it->second == 0) {
                q.push(it->first);
            }
        }

        while (!q.empty()) {
            string x = q.front();
            q.pop();
            DP[0][x] = { 0,1 };
            DP[1][x] = { 1,1 };
            for (string& c : child[x]) {
                if (DP[0][c].first == DP[1][c].first) {
                    DP[0][x].first += DP[0][c].first;
                    DP[0][x].second = 0;
                }
                else if(DP[0][c].first > DP[1][c].first){
                    DP[0][x].first += DP[0][c].first;
                    DP[0][x].second &= DP[0][c].second;
                }
                else {
                    DP[0][x].first += DP[1][c].first;
                    DP[0][x].second &= DP[1][c].second;
                }
                DP[1][x].first += DP[0][c].first;
                DP[1][x].second &= DP[0][c].second;
            }
            if (x == root) break;
            deg[parent[x]] -= 1;
            if (deg[parent[x]] == 0) q.push(parent[x]);
        }

        if (DP[0][root].first == DP[1][root].first) {
            cout << DP[0][root].first << " No";
        }
        else if (DP[0][root].first > DP[1][root].first) {
            cout << DP[0][root].first;
            if (DP[0][root].second) cout << " Yes";
            else cout << " No";
        }
        else {
            cout << DP[1][root].first;
            if (DP[1][root].second) cout << " Yes";
            else cout << " No";
        }
        cout << endl;

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