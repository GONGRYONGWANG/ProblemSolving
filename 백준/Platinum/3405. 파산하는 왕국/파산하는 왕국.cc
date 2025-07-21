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
#include<random> // rand
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
int popcount(uint n) { // https://blog.naver.com/jinhan814/222540111549
    n = (n >> 1 & 0x55555555) + (n & 0x55555555);
    n = (n >> 2 & 0x33333333) + (n & 0x33333333);
    n = (n >> 4 & 0x0F0F0F0F) + (n & 0x0F0F0F0F);
    n = (n >> 8 & 0x00FF00FF) + (n & 0x00FF00FF);
    n = (n >> 16 & 0x0000FFFF) + (n & 0x0000FFFF);
    return n;
}
///////////////////////////////////////////////////////////////

int adj[20][20];

void solve(int tc) {

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> adj[i][j];
        }
    }
    
    vector<bool> visited((1 << N), false);
    vector<int> ret;

    queue<int> q;
    q.push((1 << N) - 1);
    visited[(1 << N) - 1] = true;
    while (!q.empty()) {
        int bit = q.front();
        q.pop();
        if (popcount(bit) == 1) {
            for (int i = 0; i < N; i++) {
                if (bit & (1 << i)) ret.push_back(i + 1);
            }
            continue;
        }

        for (int i = 0; i < N; i++) {
            if (!(bit & (1 << i))) continue;
            if (visited[bit - (1 << i)]) continue;
            int debt = 0;
            for (int j = 0; j < N; j++) {
                if (!(bit & (1 << j))) continue;
                debt += adj[i][j];
            }
            if (debt <= 0) continue;
            visited[bit - (1 << i)] = true;
            q.push(bit - (1 << i));
        }
    }

    sort(ret.begin(), ret.end());
    if (ret.empty()) cout << 0;
    for (int x : ret) cout << x << " ";
    cout << endl;






}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    cin >> T;
    //fin.open("input.txt"); fout.open("output.txt");
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}