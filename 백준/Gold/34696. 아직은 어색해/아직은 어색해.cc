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

pll arr[50001];
ll dist[50001];
ll cal(int a, int b) {
    return (arr[a].first - arr[b].first) * (arr[a].first - arr[b].first)
        + (arr[a].second - arr[b].second) * (arr[a].second - arr[b].second);
}

void solve(int tc) {

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        ll x, y;
        cin >> x >> y;
        arr[i] = { x,y };
    }

    int s;
    cin >> s;
    for (int i = 1; i <= M; i++) {
        dist[i] = INF;
    }

    while (N--) {
        cout << s << endl;
        ll mx = 0;
        for (int i = 1; i <= M; i++) {
            dist[i] = min(dist[i], cal(s, i));
            mx = max(mx, dist[i]);
        }
        for (int i = 1; i <= M; i++) {
            if (dist[i] == mx) {
                s = i;
                break;
            }
        }
    }
    










    // cout << "Case #" << tc << ": " << ret << endl;
}


int main() {
    // fin.open("input.txt"); fout.open("output.txt");
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}