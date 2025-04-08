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
#define INF ll(1e18+7)
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

vector<int> E[501];
int cnt[501];

void solve(int tc) {

    int N;
    cin >> N;

    vector<int> commander;

    for (int i = 1; i <= N; i++) {
        int m;
        cin >> m;
        if (m == 0) commander.push_back(i);
        while (m--) {
            int x;
            cin >> x;
            E[x].push_back(i);
        }
    }

    for (int c : commander) {
        cnt[c] = 2;
        vector<bool> visited(N + 1, false);
        queue<int> q;
        q.push(c);
        visited[c] = true;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            cnt[x] += 1;
            for (int nx : E[x]) {
                if (visited[nx]) continue;
                visited[nx] = true;
                q.push(nx);
            }
        }
    }


    bool flag = true;
    for (int i = 1; i <= N; i++) {
        if (cnt[i] < 2) {
            cout << i << endl;
            flag = false;
        }
    }

    if (flag) cout << "BRAK";



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