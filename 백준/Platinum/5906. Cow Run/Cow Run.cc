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

int N, M, K;

int arr[14][8];

int cal(int i, int x, int a, int b) {
    return (ll(x) * (arr[i][a * 4 + b * 2] + 1) + arr[i][a * 4 + b * 2 + 1]) % M;
}

bool getand(int i, int x, bool a);

bool getor(int i, int x) {
    if (i == N) return min(x, M - x) <= K;
    bool a = randint(0, 1);
    return getand(i, x, a) || getand(i, x, !a);
}

bool getand(int i, int x, bool a) {
    bool b = randint(0, 1);
    return  getor(i + 1, cal(i, x, a, b)) && getor(i + 1, cal(i, x, a, !b));
}


void solve(int tc) {

    cin >> N >> M >> K;
    string s; cin >> s;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 8; j++) cin >> arr[i][j];
    }

    int x = 0;
    for (int i = 0; i < N; i++) {
        if (getand(i, x, true)) {
            cout << 'B';
            x = cal(i, x, true, s[i]=='B');
        }
        else {
            cout << 'T';
            x = cal(i, x, false, s[i]=='B');
        }
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