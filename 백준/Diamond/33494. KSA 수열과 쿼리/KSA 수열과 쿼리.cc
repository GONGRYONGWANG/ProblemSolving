// template: https://github.com/GONGRYONGWANG/ProblemSolving/blob/main/template.txt
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
#include<vector>
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
const ll INF = 1e18 + 7;
const int inf = 1e9 + 7;
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

ll arr[2000000];
unordered_map<ll, ll> m[2000];
ll bucketidx[2000];
ll bucketsum[2000];

void solve(int tc) {
    ll N, K;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        arr[i] %= K;
        bucketsum[i / 1000] += arr[i];
        m[i / 1000][arr[i]] += 1;
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int t, l, r;
        cin >> t >> l >> r;
        l -= 1; r -= 1;
        if (t == 1) {
            int lbck = l / 1000; int rbck = r / 1000;
            if (lbck == rbck) {
                for (int i = l; i <= r; i++) {
                    m[lbck][arr[i]] -= 1;
                    arr[i] += 1; bucketsum[lbck] += 1;
                    arr[i] %= K; 
                    m[lbck][arr[i]] += 1;
                    if (arr[i] == bucketidx[lbck]) bucketsum[lbck] -= K;
                }
                continue;
            }
            for (int i = l; i < (lbck + 1) * 1000; i++) {
                arr[i] += 1; bucketsum[lbck] += 1;
                arr[i] %= K;
                if (arr[i] == bucketidx[lbck]) bucketsum[lbck] -= K;
            }
            for (int bck = lbck + 1; bck < rbck; bck++) {
                bucketsum[bck] += 1000;
                bucketidx[bck] = (bucketidx[bck] + K - 1) % K;
                bucketsum[bck] -= K * m[bck][bucketidx[bck]];
            }
            for (int i = rbck * 1000; i <= r; i++) {
                m[rbck][arr[i]] -= 1;
                arr[i] += 1; bucketsum[rbck] += 1;
                arr[i] %= K;
                m[rbck][arr[i]] += 1;
                if (arr[i] == bucketidx[rbck]) bucketsum[rbck] -= K;
            }
        }
        else {
            int lbck = l / 1000; int rbck = r / 1000;
            ll ans = 0;
            if (lbck == rbck) {
                for (int i = l; i <= r; i++) {
                    ans += (K - bucketidx[lbck]) % K + arr[i];
                }
                cout << ans << endl;
                continue;
            }
            for (int i = l; i < (lbck + 1) * 1000; i++) {
                ans += (K - bucketidx[lbck]) % K + arr[i];
            }
            for (int bck = lbck + 1; bck < rbck; bck++) {
                ans += bucketsum[bck];
            }
            for (int i = rbck * 1000; i <= r; i++) {
                ans += (K - bucketidx[rbck]) % K + arr[i];
            }

            cout << ans << endl;
        }
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