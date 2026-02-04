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

    int N;
    cin >> N;

    vector<int> A, B;
    for (int i = 0; i < N; i++) {
        char d; int a;
        cin >> d >> a;
        if (d == 'L') A.push_back(a);
        else B.push_back(a);
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    for (int i = A.size() - 2; i >= 0; i--) {
        A[i] = min(A[i], A[i + 1] - 1);
    }
    for (int i = B.size() - 2; i >= 0; i--) {
        B[i] = min(B[i], B[i + 1] - 1);
    }

    if (!A.empty() && A[0] < 1) {
        cout << -1;
        return;
    }

    if (!B.empty() &&  B[0] < 1) {
        cout << -1;
        return;
    }

    A.push_back(inf);
    reverse(B.begin(), B.end());
    B.push_back(0);

    int aidx = 0;
    int bidx = 0;

    ll ret = 0;
    for (int i = 1; i <= N; i++) {
        if (A[aidx] > i && N + 1 - i <= B[bidx]) {
            bidx += 1;
            ret += N + 1 - i;
        }
        else {
            ret += i;
            aidx += 1;
        }
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