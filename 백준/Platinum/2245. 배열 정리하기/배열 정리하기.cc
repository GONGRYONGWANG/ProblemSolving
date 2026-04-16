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
const string debug = "debug: ";
#define all(x) (x).begin(), (x).end()
#include<fstream>
ifstream fin; ofstream fout;


//int dx[4] = { -1,0,1,0 };
//int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////


vector<pii> E[100001];
bool visited[100001];
int A[100000];
int B[100000];

void solve(int tc) {

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    for (int i = 0; i < N; i++) {
        int a = A[i]; int b = B[i];
        E[a].push_back({ b,0 });
        E[b].push_back({ a,1 });
    }

    for (int i = 1; i <= N; i++) {
        if (E[i].size() != 2) {
            cout << -1;
            return;
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (visited[i]) continue;
        int cnt = 0;
        int ret = 0;
        int x = i;
        while (1) {
            visited[x] = true;
            cnt += 1;
            if (!visited[E[x].front().first]) {
                ret += E[x].front().second;
                x = E[x].front().first;
            }
            else if (!visited[E[x].back().first]) {
                ret += E[x].back().second;
                x = E[x].back().first;
            }
            else break;
        }

        if (cnt != 1) {
            ret += !E[i].back().second;
        }

        ans += min(ret, cnt - ret);

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