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

vector<int> E[500001];
ld arr[500001];
ld sum[500001];
vector<int> HE[500001];

void solve(int tc) {

    int N;
    cin >> N;
    int sqrtN = sqrt(N);

    ld ret = 0;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        ret += arr[i];
    }

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
        sum[u] += arr[v]; sum[v] += arr[u];
        ret += arr[u] * (1 - arr[v]) + (1 - arr[u]) * arr[v];
    }

    for (int i = 1; i <= N; i++) {
        for (int nx : E[i]) {
            if (E[nx].size() >= sqrtN) HE[i].push_back(nx);
        }
    }


    int Q;
    cin >> Q;
    cout << fixed;
    cout.precision(9);
    cout << ret << endl;

    while (Q--) {
        int x; ld p;
        cin >> x >> p;
        ret += p - arr[x];
        if (E[x].size() >= sqrtN) {
            ret -= sum[x] * (1 - arr[x]) + arr[x] * (E[x].size() - sum[x]);
            ret += sum[x] * (1 - p) + p * (E[x].size() - sum[x]);
        }
        else {
            sum[x] = 0;
            for (int nx : E[x]) {
                sum[x] += arr[nx];
            }
            ret -= sum[x] * (1 - arr[x]) + arr[x] * (E[x].size() - sum[x]);
            ret += sum[x] * (1 - p) + p * (E[x].size() - sum[x]);
        }

        for (int nx : HE[x]) {
            sum[nx] -= arr[x];
            sum[nx] += p;
        }

        arr[x] = p;
        cout << ret << endl;
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