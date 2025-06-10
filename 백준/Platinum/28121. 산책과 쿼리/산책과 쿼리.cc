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

bool col[300001];
int parent[300001];
vector<int> arr[300001];

int findp(int x) {
    if (parent[x] == x) return x;
    return findp(parent[x]);
}

void solve(int tc) {

    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        arr[i] = { i };
        col[i] = 0;
    }

    while (Q--) {
        int u, v;
        cin >> u >> v;
        if (findp(u) == 0 && findp(v) == 0);
        else if (findp(u) == 0) {
            for (int x : arr[findp(v)]) arr[0].push_back(x);
            parent[findp(v)] = 0;
        }
        else if (findp(v) == 0) {
            for (int x : arr[findp(u)]) arr[0].push_back(x);
            parent[findp(u)] = 0;
        }
        else if (findp(u) == findp(v)) {
            if (col[u] == col[v]) {
                for (int x : arr[findp(u)]) arr[0].push_back(x);
                parent[findp(u)] = 0;
            }
        }
        else {
            if (arr[findp(u)].size() > arr[findp(v)].size()) swap(u, v);
            if (col[u] == col[v]) {
                for (int x : arr[findp(u)]) col[x] = !col[x];
            }
            for (int x : arr[findp(u)]) arr[findp(v)].push_back(x);
            parent[findp(u)] = findp(v);
        }
        cout << arr[0].size() << endl;
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