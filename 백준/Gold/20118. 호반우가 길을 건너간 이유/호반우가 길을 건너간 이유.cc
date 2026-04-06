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
//int dx8[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy8[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////



void solve(int tc) {

    int N, M;
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int x; cin >> x;
        }
    }

    int K = 0;
    vector<pii> ret;
    int x = -1; int y = -1;
    while (x + 2 < N && y + 2 < M) {
        K += 4;
        ret.push_back({ x + 1,y + 1 });
        ret.push_back({ x + 2,y + 2 });
        ret.push_back({ x + 1,y + 1 });
        ret.push_back({ x + 2,y + 2 });
        x += 2; y += 2;
    }

    while (x + 2 < N) {
        K += 4;
        ret.push_back({ x + 1,y });
        ret.push_back({ x + 2,y });
        ret.push_back({ x + 1,y });
        ret.push_back({ x + 2,y });
        x += 2;
    }

    while (y + 2 < M) {
        K += 4;
        ret.push_back({ x,y + 1 });
        ret.push_back({ x,y + 2 });
        ret.push_back({ x,y + 1 });
        ret.push_back({ x,y + 2 });
        y += 2;
    }

    if (x != N - 1) {
        K += 4;
        if (y == M - 1) {
            ret.push_back({ x,y - 1 });
            ret.push_back({ x + 1,y });
            ret.push_back({ x,y - 1 });
            ret.push_back({ x + 1,y });
        }
        else {
            ret.push_back({ x,y + 1 });
            ret.push_back({ x + 1,y });
            ret.push_back({ x,y + 1 });
            ret.push_back({ x + 1,y });
        }
        x += 1;
    }

    if (y != M - 1) {
        K += 4;
        ret.push_back({ x - 1,y });
        ret.push_back({ x,y + 1 });
        ret.push_back({ x - 1,y });
        ret.push_back({ x,y + 1 });
    }
    cout << K << endl;
    for (auto& [a, b] : ret) {
        cout << a << " " << b << endl;
    }


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