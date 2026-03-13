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


vector<int> mer(vector<int> A, vector<int> B) {
    vector<int> ret(3,0);
    ret[0] = (A[0] + B[0]) % 4;
    ret[1] = B[1]; ret[2] = B[2];
    if (B[0] == 0) {
        ret[1] += A[1]; ret[2] += A[2];
    }
    else if (B[0] == 1) {
        ret[1] += A[2]; ret[2] -= A[1];
    }
    else if (B[0] == 2) {
        ret[1] -= A[1]; ret[2] -= A[2];
    }
    else {
        ret[1] -= A[2]; ret[2] += A[1];
    }
    return ret;
}

pii coordinate(vector<int> v) {
    if (v[0] == 0) return { v[1],v[2] };
    else if (v[0] == 1) return { -v[2],v[1] };
    else if (v[0] == 2) return { -v[1],-v[2] };
    else return { v[2],-v[1] };
}

vector<int> arr[100001];

vector<int> prefix[100002];
vector<int> suffix[100002];

void solve(int tc) {

    string s;
    cin >> s;
    int  N = s.length();

    for (int i = 1; i <= N; i++) {
        char x = s[i - 1];
        if (x == 'F') arr[i] = { 0,1,0 };
        else if (x == 'L') arr[i] = { 3,0,0 };
        else arr[i] = { 1,0,0 };
    }

    prefix[0] = { 0,0,0 };
    for (int i = 1; i <= N; i++) {
        prefix[i] = mer(prefix[i - 1], arr[i]);
    }


    suffix[N + 1] = { 0,0,0 };
    for (int i = N; i > 0; i--) {
        suffix[i] = mer(arr[i], suffix[i + 1]);
    }

    set<pii> st;
    for (int i = 1; i <= N; i++) {
        if (s[i - 1] != 'F') st.insert(coordinate(mer(mer(prefix[i - 1], { 0,1,0 }), suffix[i + 1])));
        if (s[i - 1] != 'L')st.insert(coordinate(mer(mer(prefix[i - 1], { 3,0,0 }), suffix[i + 1])));
        if (s[i - 1] != 'R')st.insert(coordinate(mer(mer(prefix[i - 1], { 1,0,0 }), suffix[i + 1])));
    }

    cout << st.size();



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