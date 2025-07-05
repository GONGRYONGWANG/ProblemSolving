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
#define INF ll(4e18)
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


vector<int> cnt[100001];

vector<ll> v[100001];

void solve(int tc) {


    int N, K;
    cin >> N >> K;
    
    vector<pll> arr(N); // b,a
    for (int i = 0; i < N; i++) cin >> arr[i].second;
    for (int i = 0; i < N; i++) cin >> arr[i].first;
    sort(arr.rbegin(), arr.rend());

    ll ret = 0;

    for (int i = 0; i < K; i++) {
        auto [b, a] = arr.back();
        arr.pop_back();
        ret += b;
        v[a].push_back(b);
    }

    for (int i = 1; i <= N; i++) {
        cnt[v[i].size()].push_back(i);
    }

    vector<ll> ans(N + 1, -1);
    ans[N] = ret;
    for (int L = N - 1; L >= 1; L--) {
        for (int x : cnt[L + 1]) {
            if (v[x].size() <= L) continue;

            ret -= v[x].back();
            v[x].pop_back();

            while (!arr.empty() && v[arr.back().second].size() >= L) {
                arr.pop_back();
            }

            if (arr.empty()) goto End;

            auto [b, a] = arr.back();
            v[a].push_back(b);
            ret += b;
            arr.pop_back();
            cnt[v[a].size()].push_back(a);
            cnt[v[x].size()].push_back(x);
        }

        ans[L] = ret;
    }

    End:

    for (int L = 1; L <= N; L++) {
        cout << ans[L] << " ";
    }



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