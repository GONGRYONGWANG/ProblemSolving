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


bool visited[1001][1001];
int arr[1001];
struct cmp {
    bool operator()(vector<int>& a, vector<int>& b) {
        return a[2] > b[2];
    }
};

void solve(int tc) {

    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];

    pq<vector<int>, vector<vector<int>>, cmp> q;
    q.push({ 1,0,0 });

    while (!q.empty()) {
        int x = q.top()[0];
        int d = q.top()[1];
        int k = q.top()[2];
        q.pop();
        if (visited[x][d]) continue;
        visited[x][d] = true;
        if (x == N) {
            cout << k;
            return;
        }
        if (x - d >= 1 && !visited[x - d][d]) {
            q.push({ x - d,d,k + arr[x - d] });
        }
        if (x + d + 1 <= N && !visited[x + d + 1][d + 1]) {
            q.push({ x + d + 1,d + 1,k + arr[x + d + 1] });
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