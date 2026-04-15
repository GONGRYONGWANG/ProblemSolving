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


int N, K;

bool iter(vector<int>& arr, vector<bool>& robot) {
    vector<int> nxarr(2 * N); vector<bool> nxrobot(2 * N);
    for (int i = 0; i < 2 * N; i++) {
        nxarr[(i + 1) % (2 * N)] = arr[i];
        nxrobot[(i + 1) % (2 * N)] = robot[i];
    }
    nxrobot[N - 1] = false;
    for (int i = N - 1; i >= 0; i--) {
        if (!nxrobot[i]) continue;
        if (!nxarr[i + 1]) continue;
        if (nxrobot[i + 1]) continue;
        nxrobot[i] = false;
        nxrobot[i + 1] = true;
        nxarr[i + 1] -= 1;
    }
    nxrobot[N - 1] = false;
    if (!nxrobot[0] && nxarr[0]) {
        nxrobot[0] = true;
        nxarr[0] -= 1;
    }

    int cnt = 0;
    for (int i = 0; i < 2 * N; i++) {
        cnt += (nxarr[i] == 0);
    }
    arr = nxarr; robot = nxrobot;
    return (cnt < K);
}

void solve(int tc) {
    
    cin >> N >> K;
    vector<int> arr(2 * N);
    vector<bool> robot(2 * N, false);
    for (int& x : arr) cin >> x;

    int ret = 1;
    while (iter(arr, robot)) {
        ret += 1;
    }

    cout << ret;




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