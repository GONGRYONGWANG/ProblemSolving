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

int cnt[2000];
int board[2000][2000];

void solve(int tc) {

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    for (int j = 1; j < M; j++) {
        for (int i = 1; i < N; i++) {
            cnt[i] += (board[i][j] != board[0][j]);
        }
    }

    bool flag = true;
    int x = 0;
    vector<bool> visited(2001, false);

    for (int i = 1; i < N; i++) {
        if (cnt[i] >= 2) {
            flag = false; break;
        }
        if (cnt[i] == 1) {
            if (board[i][0] == board[0][0] || (x != 0 && x != board[i][0])) {
                flag = false; break;
            }
            x = board[i][0];
        }
        else visited[board[i][0]] = true;
    }
    if (visited[x]) flag = false;


    if (flag) {
        cout << x << " ";
        for (int j = 1; j < M; j++) cout << board[0][j] << " ";
        return;
    }

    for (int j = 1; j < M; j++) {
        for (int i = 1; i < N; i++) {
            cnt[i] -= (board[i][j] != board[0][j]);
            cnt[i] += (board[i][j - 1] != board[0][j - 1]);
        }

        x = 0;
        visited.clear(); visited.resize(2001, false);
        flag = true;

        for (int i = 1; i < N; i++) {
            if (cnt[i] >= 2) {
                flag = false; break;
            }
            if (cnt[i] == 1) {
                if (board[i][j] == board[0][j] || (x != 0 && x != board[i][j])) {
                    flag = false; break;
                }
                x = board[i][j];
            }
            else visited[board[i][j]] = true;
        }
        if (visited[x]) flag = false;

        if (flag) {
            for (int k = 0; k < j; k++) cout << board[0][k] << " ";
            cout << x << " ";
            for (int k = j + 1; k < M; k++) cout << board[0][k] << " ";
            return;
        }
        

    }




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