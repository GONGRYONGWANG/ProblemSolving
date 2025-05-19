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

vector<int> E[50];
int ind[50];
int DP[50];
int sz[50];
int parent[50];
int findp(int x) {
    if (parent[x] == x) return x;
    return parent[x] = findp(parent[x]);
}

void solve(int tc) {

    int N, K;
    cin >> N >> K;

    vector<vector<int>> arr(N); // x,y,length
    for (int i = 0; i < N; i++) {
        parent[i] = i;
        int x, y, l;
        cin >> sz[i] >> x >> y >> l;
        arr[i] = { x,y,l };
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            int s1 = arr[i][0]; int y1 = arr[i][1]; int e1 = s1 + arr[i][2];
            int s2 = arr[j][0]; int y2 = arr[j][1]; int e2 = s2 + arr[j][2];
            if (y1 != y2) continue;
            if (s1 > s2) swap(s1, s2), swap(e1, e2);
            if (s2 - e1 > K) continue;
            if (findp(i) == findp(j)) continue;
            sz[findp(i)] += sz[findp(j)];
            parent[findp(j)] = findp(i);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            int s1 = arr[i][0]; int y1 = arr[i][1]; int e1 = s1 + arr[i][2];
            int s2 = arr[j][0]; int y2 = arr[j][1]; int e2 = s2 + arr[j][2];
            if (y1 >= y2) continue;
            if (s1 > s2) swap(s1, s2), swap(e1, e2);
            if ((y2 - y1) * (y2 - y1) + max(0, s2 - e1) * max(0, s2 - e1) > K * K) continue;
            E[findp(i)].push_back(findp(j));
            ind[findp(j)] += 1;
        }
    }

    queue<int> q;

    for (int i = 0; i < N; i++) {
        DP[i] = -inf;
        if (ind[i] == 0 && findp(i) == i) {
            q.push(i);
            if (arr[i][1] <= K) DP[i] = 0;
        }
    }

    int ans = 0;
    
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        DP[x] += sz[x];
        ans = max(ans, DP[x]);
        for (int nx : E[x]) {
            ind[nx] -= 1;
            DP[nx] = max(DP[nx], DP[x]);
            if (ind[nx] == 0) q.push(nx);
        }
    }

    cout << ans;


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