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
const long double pi = acosl(-1);
const string debug = "debug: ";
#define all(x) (x).begin(), (x).end()

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


int parent[200001];
int ind[200001];
vector<int> child[200001];
map<int,int> m[200001];
int mex[200001];

void solve(int tc) {


    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> parent[i];
        if (parent[i] != -1) {
            ind[parent[i]] += 1;
            child[parent[i]].push_back(i);
        }
    }

    for (int i = 1; i <= N; i++) {
        int v; cin >> v;
        m[i][v] = v;
    }

    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (ind[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (int c : child[x]) {
            if (m[x].size() < m[c].size()) swap(m[x], m[c]);
            for (auto [l, r] : m[c]) {
                auto it = m[x].upper_bound(l);
                if (it != m[x].begin() && prev(it)->second + 1 >= l ) {
                    it = prev(it);
                    it->second = max(it->second, r);
                    while (next(it) != m[x].end() && it->second + 1 >= next(it)->first) {
                        it->second = max(it->second, next(it)->second);
                        m[x].erase(next(it));
                    }
                }
                else if (it != m[x].end() && it->first <= r + 1) {
                    while (it != m[x].end() && it->first <= r + 1) {
                        r = max(r, it->second);
                        it = next(it);
                        m[x].erase(prev(it));
                    }
                    m[x][l] = r;
                }
                else {
                    m[x][l] = r;
                }
            }
        }

        if (m[x].begin()->first != 0) mex[x] = 0;
        else mex[x] = m[x].begin()->second + 1;

        if (parent[x] != -1) {
            ind[parent[x]] -= 1;
            if (ind[parent[x]] == 0) q.push(parent[x]);
        }
    }

    for (int i = 1; i <= N; i++) cout << mex[i] << endl;






    // cout << "Case #" << tc << ": " << ret << endl;
}


int main() {
    //fin.open("input.txt"); fout.open("output.txt");
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}