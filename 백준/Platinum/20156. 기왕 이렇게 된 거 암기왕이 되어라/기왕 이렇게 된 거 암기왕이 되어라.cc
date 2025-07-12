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
#define INF ll(2e18)
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

int E[100001];
int init[100001];

int parent[100001];
int findp(int x) {
    if (parent[x] == x) return x;
    return parent[x] = findp(parent[x]);
}

void solve(int tc) {

    int N, M, K;
    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) {
        cin >> E[i];
        if (E[i] == -1) E[i] = i;
    }

    vector<int> arr(M);
    for (int i = 0; i < M; i++) {
        cin >> arr[i];
        init[arr[i]] += 1;
    }

    reverse(arr.begin(), arr.end());

    vector<vector<int>> query(K);
    for (int i = 0; i < K; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        query[i] = { M - a,b,c,i };
    }
    sort(query.begin(), query.end());

    for (int i = 1; i <= N; i++) parent[i] = i;
    for (int i = 1; i <= N; i++) {
        if (!init[i]) parent[findp(i)] = findp(E[i]);
    }

    vector<bool> ans(K);

    int qidx = 0;
    for (int i = 0; i <= M; i++) {
        while (qidx != K && query[qidx][0] == i) {
            int b = query[qidx][1]; int c = query[qidx][2];
            ans[query[qidx][3]] = (findp(b) == findp(c));
            qidx += 1;
        }
        if (i == M) break;
        init[arr[i]] -= 1;
        if (init[arr[i]] == 0) parent[findp(arr[i])] = findp(E[arr[i]]);
    }

    for (int i = 0; i < K; i++) {
        cout << (ans[i] ? "Same Same;" : "No;") << endl;
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