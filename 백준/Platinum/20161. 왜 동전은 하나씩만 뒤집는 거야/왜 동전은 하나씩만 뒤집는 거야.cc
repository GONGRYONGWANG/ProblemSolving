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

int arr[100];
bool visited[100][(1 << 10)];

void solve(int tc) {

    int N, K;
    cin >> N >> K;

    for (int i = 0; i < N; i++) cin >> arr[i];
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        arr[i] ^= x;
    }
    
    int e = 0;
    for (int i = N - K; i < N; i++) {
        e <<= 1;
        e += arr[i];
    }

    deque<tuple<int,int,int>> q;
    q.push_back({ 0,0,0 });
    while (!q.empty()) {
        auto [x, bit, d] = q.front();
        q.pop_front();
        if (visited[x][bit]) continue;
        visited[x][bit] = true;
        if (x + K == N && bit == e) {
            cout << d;
            return;
        }
        if (x + K < N && arr[x] == (bit >> (K - 1)) && !visited[x + 1][(bit - (bit & (1 << (K - 1)))) << 1]) {
            q.push_front({ x + 1, (bit - (bit & (1 << (K - 1)))) << 1, d });
            
        }
        bit ^= (1 << K) - 1;
        for (int j = 0; j < K; j++) {
            int nxbit = bit ^ (1 << j);
            if (visited[x][nxbit]) continue;
            q.push_back({ x,nxbit, d + 1 });
        }
    }


    cout << -1;


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