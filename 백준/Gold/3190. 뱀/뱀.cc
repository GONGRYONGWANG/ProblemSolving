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

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////


bool board[101][101];
bool apple[101][101];

void solve(int tc) {
    
    int N, K;
    cin >> N >> K;

    while (K--) {
        int x, y;
        cin >> x >> y;
        apple[x][y] = true;
    }

    int L;
    cin >> L;
    
    vector<pii> arr(L);
    for (int i = 0; i < L; i++) {
        int x; char c;
        cin >> x >> c;
        arr[i] = { x, (c == 'L') };
    }

    int ret = 0;

    deque<pii> q;
    q.push_back({ 1,1 });
    board[1][1] = true;
    int dir = 1;
    
    int idx = 0;

    while (1) {
        ret += 1;
        
        auto [x, y] = q.back();
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx<1 || nx>N || ny<1 || ny>N || board[nx][ny]) {
            cout << ret;
            return;
        }

        q.push_back({ nx,ny });
        board[nx][ny] = true;

        if (!apple[nx][ny]) {
            board[q.front().first][q.front().second] = false;
            q.pop_front();
        }
        else apple[nx][ny] = false;

        if (idx != L && arr[idx].first == ret) {
            if (arr[idx].second) dir += 3;
            else dir += 1;
            dir %= 4;
            idx += 1;
        }

    }




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