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


//int dx[4] = { -1,0,1,0 }; 
//int dy[4] = { 0,-1,0,1 }; 
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////
struct PiiHasher { // unordered_set<pii, PiiHasher>
    size_t operator()(const pii& x) const {
        return hash<long long>()(((long long)x.first) ^ (((long long)x.second) << 32));
    }
};

///////////////////////////////////////////////////////////////

vector<int> E[101];
bool visited[101];
bool col[101];

void solve(int tc) {

    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int K;
        cin >> K;
        while (K--) {
            int x;
            cin >> x;
            E[i].push_back(x);
        }
    }

    int cnt = 0;

    for (int i = 1; i <= N; i++) {
        if (visited[i]) continue;
        col[i] = true;
        queue<int> q;
        q.push(i);
        visited[i] = true;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            cnt += col[x];
            for (int nx : E[x]) {
                if (visited[nx]) continue;
                visited[nx] = true;
                col[nx] = !col[x];
                q.push(nx);
            }
        }
    }

    cout << cnt << endl;
    for (int i = 1; i <= N; i++) {
        if (col[i]) cout << i << " ";
    }
    cout << endl;
    cout << N - cnt << endl;
    for (int i = 1; i <= N; i++) {
        if (!col[i]) cout << i << " ";
    }




}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}