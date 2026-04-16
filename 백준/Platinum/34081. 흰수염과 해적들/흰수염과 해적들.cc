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
///////////////////////////////////////////////////////////////

bool cmp(vector<ll>& a, vector<ll>& b) {
    return a[0] * a[0] + a[1] * a[1] > b[0] * b[0] + b[1] * b[1];
}

void solve(int tc) {

    ll N, L;
    cin >> N >> L;

    vector<vector<ll>> arr(N);
    for (int i = 0; i < N; i++) {
        ll x, y, c;
        cin >> x >> y >> c;
        arr[i] = { x,y,c };
    }

    sort(arr.begin(), arr.end(), cmp);

    pq<ll, vector<ll>, greater<ll>> q;
    ll ans = 0;

    for (int i = 0; i < N; i++) {
        ll x, y, c;
        x = arr[i][0]; y = arr[i][1]; c = arr[i][2];
        if (x * x + y * y > L * L) continue;

        ll sqr = sqrt(x * x + y * y);

        ll t;
        if (sqr * sqr >= x * x + y * y) {
            t = L - sqr + 1;
        }
        else {
            t = L - sqr;
        }

        if (q.size() < t) {
            ans += c;
            q.push(c);
        }
        else if (!q.empty() && q.top() < c) {
            ans -= q.top(); ans += c;
            q.pop(); q.push(c);
        }
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