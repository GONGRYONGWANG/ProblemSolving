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
const long double pi = acosl(-1);
const string debug = "debug: ";
#define all(x) (x).begin(), (x).end()

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



int arr[301];
bitset<300001> pre[301];
bitset<300001> suf[302];

void solve(int tc) {

    int N;
    cin >> N;
    
    int total = 0;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        total += arr[i];
    }

    pre[0][0] = true;
    for (int i = 1; i <= N; i++) {
        pre[i] = (pre[i - 1] | (pre[i - 1] << arr[i]));
    }

    suf[N+1][0] = true;
    for (int i = N; i >= 1; i--) {
        suf[i] = (suf[i + 1] | (suf[i + 1] << arr[i]));
    }


    vector<int> ret;
    for (int i = 1; i <= N; i++) {
        if ((total - arr[i]) % 2) continue;
        for (int j = 0; j <= (total - arr[i]) / 2; j++) {
            if (pre[i - 1][j] && suf[i + 1][(total - arr[i]) / 2 - j]) {
                ret.push_back(i);
                break;
            }
        }
    }

    cout << ret.size() << endl;
    for (int ans : ret) cout << ans << " ";
    

    // cout << "Case #" << tc << ": " << ret << endl;
}


int main() {
    //fin.open("input.txt"); fout.open("output.txt");
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}