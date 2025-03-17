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

int arr[200001];
int cnt[200001];
int parent[200001];
int DP[200001][2];
vector<int> child[200001];

void dfs(int x, bool b, vector<int>& ret) {
    if (b) {
        ret.push_back(x);
        for (int nx : child[x]) {
            dfs(nx, false, ret);
        }
        return;
    }
    else {
        for (int nx : child[x]) {
            if (DP[nx][1] >= DP[nx][0]) dfs(nx, true, ret);
            else dfs(nx, false, ret);
        }
        return;
    }
}

void solve(int tc) {

    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        DP[i][1] = arr[i];
    }

    for (int i = 2; i <= N; i++) {
        cin >> parent[i];
        cnt[parent[i]] += 1;
        child[parent[i]].push_back(i);
    }

    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (cnt[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        int p = parent[x];
        DP[p][1] += DP[x][0];
        DP[p][0] += max(DP[x][1], DP[x][0]);
        cnt[p] -= 1;
        if (cnt[p] == 0) q.push(p);
    }

    cout << DP[1][1] << " " << DP[1][0] << endl;

    vector<int> ret;
    dfs(1, true, ret);
    sort(ret.begin(), ret.end());
    ret.push_back(-1);
    for (int x : ret) {
        cout << x << " ";
    }
    cout << endl;
    ret.clear();
    dfs(1, false, ret);
    sort(ret.begin(), ret.end());
    ret.push_back(-1);
    for (int x : ret) {
        cout << x << " ";
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