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


int nx[400000][18];

void solve(int tc) {
    
    int N, M;
    cin >> N >> M;

    vector<pii> arr(N);
    for (int i = 0; i < N; i++) {
        int s, e;
        cin >> s >> e;
        if (e < s) e += M;
        arr[i] = { s,e };
    }

    sort(arr.begin(), arr.end());

    deque<pii> q;
    for (auto [s, e] : arr) {
        if (!q.empty() && q.back().second >= e) continue;
        q.push_back({ s,e });
    }

    while (q.size() >= 2 && q.back().second - M >= q.front().second) q.pop_front();

    N = q.size();

    for (int i = 0; i < N - 1; i++) {
        if (q[i].second < q[i + 1].first) {
            cout << -1;
            return;
        }
    }
    if (q.back().second - M < q.front().first) {
        cout << -1;
        return;
    }

    arr.clear();
    arr.resize(N);

    for (int i = 0; i < N; i++) arr[i] = q[i];

    for (int i = 0; i < N; i++) {
        arr.push_back({ arr[i].first + M,arr[i].second + M });
    }

    int idx = 0;
    for (int i = 0; i < 2 * N; i++) {
        while (idx != 2 * N && arr[i].second >= arr[idx].first) idx += 1;
        nx[i][0] = idx - 1;
    }

    for (int j = 1; j < 18; j++) {
        for (int i = 0; i < 2 * N; i++) {
            nx[i][j] = nx[nx[i][j - 1]][j - 1];
        }
    }

    int ans = inf;
    for (int i = 0; i < N; i++) {
        int ret = 2;
        int x = i;
        for (int j = 17; j >= 0; j--) {
            if (arr[nx[x][j]].second < arr[i].first + M) {
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