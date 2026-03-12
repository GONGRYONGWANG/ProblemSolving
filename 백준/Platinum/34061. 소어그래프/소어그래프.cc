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
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////



void solve(int tc) {
    
    ll N, X, Y, t;
    cin >> N >> X >> Y >> t;

    int d = 0;
    {
        vector<int> visited((1 << 20) + 1, 0);
        queue<int> q;
        q.push(0); visited[0] = 1;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            if (x == (1 << 20)) break;
            int nx = x ^ t;
            if (!visited[nx]) {
                visited[nx] = visited[x] + 1;
                q.push(nx);
            }
            nx += 1;
            if (!visited[nx]) {
                visited[nx] = visited[x] + 1;
                q.push(nx);
            }
        }

        d = visited[(1 << 20)] - 1;
    }

    if ((X >> 20) > (Y >> 20)) {
        cout << -1;
        return;
    }

    ll ret = 0;
    if ((X >> 20) < (Y >> 20)) {
        if ((Y >> 20) - (X >> 20) > 1 && d ==0) {
            cout << -1;
            return;
        }
        ret += ((Y >> 20) - (X >> 20) - 1) * d;
        vector<int> visited((1 << 20) + 1, 0);
        queue<int> q;
        int a = X % (1 << 20);
        q.push(a);  visited[a] = 1;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            if (x == (1 << 20)) break;
            int nx = x ^ t;
            if (!visited[nx]) {
                visited[nx] = visited[x] + 1;
                q.push(nx);
            }
            nx += 1;
            if (!visited[nx]) {
                visited[nx] = visited[x] + 1;
                q.push(nx);
            }
        }
        if (!visited[(1 << 20)]) {
            cout << -1;
            return;
        }
        ret += visited[(1 << 20)] - 1;
        X = 0;
    }

    X %= (1 << 20);
    if ((Y >> 20) == (N >> 20)) N %= (1 << 20);
    else N = (1 << 20) + 10;
    Y %= (1 << 20);


    queue<int> q;
    vector<int> visited((1 << 20) + 1, 0);
    visited[X] = 1;
    q.push(X);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (x == (1 << 20)) continue;
        int nx = x ^ t;
        if (!visited[nx] && nx < N) {
            visited[nx] = visited[x] + 1;
            q.push(nx);
        }
        nx += 1;
        if (!visited[nx] && nx < N) {
            visited[nx] = visited[x] + 1;
            q.push(nx);
        }
    }

    if (!visited[Y]) {
        cout << -1;
        return;
    }
    
    cout << ret + visited[Y] - 1;

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