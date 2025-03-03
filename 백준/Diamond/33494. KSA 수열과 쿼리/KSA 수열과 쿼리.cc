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
bool finish[2000000];
ll total[1415];
ll idx[1415];
ll cnt[1415][20001];
ll sqrtN;
ll N, K;

void solve(int tc) {

    cin >> N >> K;
    sqrtN = sqrt(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        arr[i] %= K;
        total[i / sqrtN] += arr[i];
        arr[i] = (K - arr[i]) % K;
        if (arr[i] <= 20000) cnt[i / sqrtN][arr[i]] += 1;
        else finish[i] = true;
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int t, l, r;
        cin >> t >> l >> r;
        l -= 1; r -= 1;
        int lbck = l / sqrtN; int rbck = r / sqrtN;
        if (t == 1) {
            if (lbck == rbck) {
                for (int i = l; i <= r; i++) {
                    total[lbck] += 1;

                    if(!finish[i]) cnt[lbck][arr[i]] -= 1;

                    arr[i] -= 1;
                    if (arr[i] == -1) arr[i] = K - 1;
                    if (arr[i] == idx[lbck]) total[lbck] -= K;
                    if (arr[i] > 20000) finish[i] = true;
                    if (!finish[i]) cnt[lbck][arr[i]] += 1;
                }
                continue;
            }

            for (int i = l; i < (lbck + 1) * sqrtN; i++) {
                total[lbck] += 1;

                if (!finish[i]) cnt[lbck][arr[i]] -= 1;

                arr[i] -= 1;
                if (arr[i] == -1) arr[i] = K - 1;
                if (arr[i] == idx[lbck]) total[lbck] -= K;
                if (arr[i] > 20000) finish[i] = true;
                if (!finish[i]) cnt[lbck][arr[i]] += 1;
            }
            for (int bck = lbck + 1; bck < rbck; bck++) {
                total[bck] += sqrtN;
                idx[bck] += 1;
                if (idx[bck] == K) idx[bck] = 0;
                total[bck] -= cnt[bck][idx[bck]] * K;
            }
            for (int i = rbck * sqrtN; i <= r; i++) {
                total[rbck] += 1;

                if (!finish[i]) cnt[rbck][arr[i]] -= 1;

                arr[i] -= 1;
                if (arr[i] == -1) arr[i] = K - 1;
                if (arr[i] == idx[rbck]) total[rbck] -= K;
                if (arr[i] > 20000) finish[i] = true;
                if (!finish[i]) cnt[rbck][arr[i]] += 1;
            }
        }
        else {
            ll ret = 0;
            if (lbck == rbck) {
                for (int i = l; i <= r; i++) {
                    ret += (K - arr[i] % K + idx[lbck]) % K;
                }
                cout << ret << endl;
                continue;
            }

            for (int i = l; i < (lbck + 1) * sqrtN; i++) {
                ret += (K - arr[i] % K + idx[lbck]) % K;
            }
            for (int bck = lbck + 1; bck < rbck; bck++) {   
                ret += total[bck];
            }
            for (int i = rbck * sqrtN; i <= r; i++) {
                ret += (K - arr[i] % K + idx[rbck]) % K;
            }
            cout << ret << endl;
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