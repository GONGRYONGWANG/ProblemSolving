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


int nx[2000000][21];

void solve(int tc) {
    
    int N, K;
    cin >> N >> K;

    vector<pii> arr(K);
    for (int i = 0; i < K; i++) {
        int s, e;
        cin >> s >> e;
        if (e < s) e += N;
        arr[i] = { s,e };
    }

    sort(arr.begin(), arr.end());

    deque<pii> q;
    for (auto [s, e] : arr) {
        if (!q.empty() && q.back().second >= e) continue;
        q.push_back({ s,e });
    }

    while (q.front().second <= q.back().second - N) q.pop_front();

    K = q.size();

    //for (int i = 0; i < K; i++) cout << q[i].first << " " << q[i].second << endl;

    for (int i = 0; i < K - 1; i++) {
        if (q[i].second + 1 < q[i + 1].first) {
            cout << "impossible";
            return;
        }
    }

    if (q.back().second - N + 1 < q.front().first) {
        cout << "impossible";
        return;
    }
    
    for (int i = 0; i < K; i++) {
        if (q[i].second == q[i].first + N - 1) {
            cout << 1;
            return;
        }
        q.push_back({ q[i].first + N, q[i].second + N });
    }


    int idx = 0;
    for (int i = 0; i < 2 * K; i++) {
        while (idx != 2 * K && q[i].second + 1 >= q[idx].first) idx += 1;
        nx[i][0] = idx - 1;
    }


    for (int j = 1; j <= 20; j++) {
        for (int i = 0; i < 2 * K; i++) {
            nx[i][j] = nx[nx[i][j - 1]][j - 1];
        }
    }

    int ans = inf;
    for (int i = 0; i < K; i++) {
        int ret = 2;
        int x = i;
        for (int j = 20; j >= 0; j--) {
            if (q[nx[x][j]].second < q[i].first + N - 1) {
                x = nx[x][j];
                ret += (1 << j);
            }
        }
        ans = min(ans, ret);
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