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
#define INF ll(9e18)
const int inf = 1e9 + 7;
const long double pi = 3.14159265358979323846;
const string debug = "output: ";
#define all(x) (x).begin(), (x).end()
#include<fstream>
ifstream fin; ofstream fout;

int dx[4] = { -1,0,1,0 }; 
int dy[4] = { 0,-1,0,1 }; 
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

ll DP[401][401][201];   
bool inq[401][401][201];
bool ob[401][401];


void solve(int tc) {


    int a, b;
    cin >> a >> b;

    int T;
    cin >> T;

    int A, B;
    cin >> A >> B;

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        x += 200 - a; y += 200 - b;
        if (x < 0 || x>400 || y < 0 || y>400) continue;
        ob[x][y] = true;
    }


    A += 200 - a; B += 200 - b;
    if (A < 0 || A>400 || B < 0 || B>400) {
        cout << 0;
        return;
    }

    ll mod = 1e9 + 7;

    ll ans = 0;

    queue<vector<int>> q;
    q.push({ 200,200,0 });
    DP[200][200][0] = 1;
    while (!q.empty()) {
        int x = q.front()[0];
        int y = q.front()[1];
        int t = q.front()[2];
        q.pop();
        if (x == A && y == B) {
            ans = (ans+DP[A][B][t])%mod;
            continue;
        }
        if (t == T) continue;
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int nt = t + 1;
            if (ob[nx][ny]) continue;
            DP[nx][ny][nt] = (DP[nx][ny][nt] + DP[x][y][t]) % mod;
            if (inq[nx][ny][nt]) continue;
            inq[nx][ny][nt] = true;
            q.push({ nx,ny,nt });
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