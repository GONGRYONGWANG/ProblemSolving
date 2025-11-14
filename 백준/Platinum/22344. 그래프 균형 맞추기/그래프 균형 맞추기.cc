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


vector<pll> E[100001];
int col[100001];

ll arr[100001];
bool visited[100001];

void solve(int tc){

    int N, M;
    cin >> N >> M;

    while (M--) {
        int u, v, w;
        cin >> u >> v >> w;
        E[u].push_back({ v,w });
        E[v].push_back({ u,w });
    }

    queue<int> q;
    q.push(1);
    col[1] = 1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto& [nx, w] : E[x]) {
            if (col[nx]) continue;
            col[nx] = 3 - col[x];
            q.push(nx);
        }
    }

    int a = 0, b = 0, c = 0;

    for (int i = 1; i <= N; i++) {
        for (auto& [nx, w] : E[i]) {
            if (col[nx] == col[i]) {
                a = i; b = nx; c = w;
            }
        }
    }

    if (a != 0) {
        q.push(a);
        arr[a] = 0;
        visited[a] = true;
        while(!q.empty()) {
            int x = q.front();
            q.pop();
            for (auto& [nx, w] : E[x]) {
                if (visited[nx]) continue;
                if (x == a && nx == b) continue;
                visited[nx] = true;
                arr[nx] = w - arr[x];
                q.push(nx);
            }
        }

        if (abs(c - arr[b]) % 2) {
            cout << "No";
            return;
        }

        arr[a] = (c - arr[b]) / 2;
        for (int i = 1; i <= N; i++) visited[i] = false;
        q.push(a);
        visited[a] = true;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (auto& [nx, w] : E[x]) {
                if (visited[nx]) continue;
                visited[nx] = true;
                arr[nx] = w - arr[x];
                q.push(nx);
            }
        }

        for (int i = 1; i <= N; i++) {
            for (auto& [nx, w] : E[i]) {
                if (arr[i] + arr[nx] != w) {
                    cout << "No";
                    return;
                }
            }
        }

        cout << "Yes" << endl;
        for (int i = 1; i <= N; i++) {
            cout << arr[i] << " ";
        }
        return;
    }

    arr[1] = 0;
    visited[1] = true;
    q.push(1);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto& [nx, w] : E[x]) {
            if (visited[nx]) continue;
            visited[nx] = true;
            arr[nx] = w - arr[x];
            q.push(nx);
        }
    }

    for (int i = 1; i <= N; i++) {
        for (auto& [nx, w] : E[i]) {
            if (arr[i] + arr[nx] != w) {
                cout << "No";
                return;
            }
        }
    }

    vector<ll> v(N);
    for (int i = 1; i <= N; i++) {
        if (col[i] == 1) v[i - 1] = -arr[i];
        else v[i - 1] = arr[i];
    }
    sort(v.begin(), v.end());

    cout << "Yes" << endl;
    for (int i = 1; i <= N; i++) {
        if (col[i]== 1) arr[i] += v[N / 2];
        else arr[i] -= v[N / 2];
        cout << arr[i] << " ";
    }




    // cout << "Case #" << tc << ": " << ret<< endl;
}

int main() {
    //fin.open("input.txt"); fout.open("output.txt");
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}