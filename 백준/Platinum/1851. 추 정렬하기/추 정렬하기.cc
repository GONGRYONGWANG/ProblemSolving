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
///////////////////////////////////////////////////////////////


void solve(int tc) {

    int N;
    cin >> N;

    vector<ll> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];
    map<ll, int> m;
    for (int i = 0; i < N; i++) m[arr[i]] = 0;

    vector<ll> W(N);

    int idx = 0;
    for (auto it = m.begin(); it != m.end(); it++) {
        it->second = idx; 
        W[idx] = it->first;
        idx++;
    }

    for (int i = 0; i < N; i++) {
        arr[i] = m[arr[i]];
    }

    ll ans = 0;
    vector<bool> visited(N, false);
    for (int i = 0; i < N; i++) {
        if (visited[i]) continue;
        visited[i] = true;
        if (arr[i] == i) continue;
        ll mn = W[arr[i]];
        ll cnt = 1;
        ll total = W[arr[i]];
        int x = arr[i];
        while(!visited[x]) {
            visited[x] = true;
            total += W[arr[x]];
            mn = min(mn, W[arr[x]]);
            cnt += 1;
            x = arr[x];
        }
        ans += min(total - mn + mn * (cnt - 1), mn + W[0] + total - mn + W[0] * (cnt - 1) + mn + W[0]);
    }

    cout << ans;




}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    //fin.open("input.txt"); fout.open("output.txt");
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}