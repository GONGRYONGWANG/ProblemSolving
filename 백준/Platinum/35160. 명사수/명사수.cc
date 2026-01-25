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


ll arr[2000000];

void solve(int tc) {

    int N, Q, C;
    cin >> N >> Q >> C;

    for (int i = 0; i < N; i++) cin >> arr[i];
    for (int i = N; i < Q + N; i++) {
        arr[i] = arr[i % N];
    }

    if (N <= C) {
        deque<int> q;
        for (int i = 0; i < N; i++) {
            while (!q.empty() && arr[i] - i >= arr[q.back()] - q.back()) q.pop_back();
            q.push_back(i);
        }

        ll ret = 0;
        for (int i = 0; i < Q; i++) {
            ret += arr[q.front()] + C - 1 - (q.front() - i);
            if (q.front() == i) q.pop_front();
            while (!q.empty() && arr[i + N] - (i + N) >= arr[q.back()] - q.back()) q.pop_back();
            q.push_back(i + N);
        }

        cout << ret;
        return;
    }

    deque<int> a, b;
    for (int i = 0; i < C; i++) {
        while (!a.empty() && arr[i] - i >= arr[a.back()] - a.back()) a.pop_back();
        a.push_back(i);
    }
    for (int i = C; i < N; i++) {
        while (!b.empty() && arr[i] >= arr[b.back()]) b.pop_back();
        b.push_back(i);
    }
    
    ll ret = 0;
    for (int i = 0; i < Q; i++) {
        ret += max(arr[a.front()] + C - 1 - (a.front() - i), arr[b.front()]);
        if (a.front() == i) a.pop_front();
        while (!a.empty() && arr[i + C] - (i + C) >= arr[a.back()] - a.back()) a.pop_back();
        a.push_back(i + C);
        if (b.front() == i + C) b.pop_front();
        while (!b.empty() && arr[i + N] >= arr[b.back()]) b.pop_back();
        b.push_back(i + N);
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