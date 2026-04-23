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
#include<complex> // complex number
#include<numeric>
#include<cassert>
#include <climits>
#include <immintrin.h> // AVX, AVX2, AVX-512 // #pragma GCC optimize ("O3,unroll-loops") //#pragma GCC target ("avx,avx2,fma")
#include<chrono>
using namespace std;
using ll = long long;
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

#include<random> // rand
std::mt19937 gen;
void rng_init() {
    std::random_device rd;
    gen.seed(rd());  // main에서 1번
}
int randint(int l, int r) {
    std::uniform_int_distribution<int> dist(l, r);
    return dist(gen);
}

#include<fstream>
ifstream fin; ofstream fout;

//#define cin fin 
//#define cout fout

//int dx[4] = { -1,0,1,0 };
//int dy[4] = { 0,1,0,-1 };
//int dx8[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy8[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////


int N, M;

vector<pii> arr;
int A[8];
int H[8];
int P[8];

vector<pii> ret;

bool dfs(int n) {
    if (n == N) {
        vector<bool> v(14, false);
        for (int i = 1; i <= N; i++) {
            if (A[i] <= 0) continue;
            v[A[i]] = true;
        }
        for (int j = 1; j <= M; j++) {
            if (H[j] <= 0) continue;
            v[H[j]] = true;
        }

        int h = 1;
        while (v[h]) h += 1;

        for (int j = 1; j <= M; j++) {
            if (H[j] > h) return false;
        }

        return true;
    }

    if (dfs(n + 1)) return true;

    for (int j = 1; j <= M; j++) {
        if (H[j] <= 0) continue;
        H[j] -= arr[n].first;
        A[arr[n].second] -= P[j];
        ret.push_back({ arr[n].second,j });
        if (dfs(n + 1)) return true;
        H[j] += arr[n].first;
        A[arr[n].second] += P[j];
        ret.pop_back();
    }

    return false;
}

void solve(int tc) {

    cin >> N >> M;

    arr.resize(N);
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        arr[i] = { x,i + 1 };
        A[i + 1] = y;
    }

    sort(arr.begin(), arr.end());

    for (int i = 1; i <= M; i++) {
        int x, y;
        cin >> x >> y;
        H[i] = y;
        P[i] = x;
    }
    
    if (!dfs(0)) {
        cout << -1;
        return;
    }

    cout << ret.size() + 1 << endl;
    for (auto& [a, b] : ret) {
        cout << "attack " << a << " " << b << endl;
    }
    cout << "use modok";



    // cout << "Case #" << tc << ": " << ret << endl;
}


int main() {
    //fin.open("input.txt"); fout.open("output.txt");
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    rng_init();
    int T = 1;
    //cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}