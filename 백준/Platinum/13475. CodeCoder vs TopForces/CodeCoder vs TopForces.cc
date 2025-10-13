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
//#define cin fin 
//#define cout fout

//int dx[4] = { -1,0,1,0 };
//int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////

int N;
bool visited[100000];
vector<int> nx[100000];
int ret[100000];

void solve(int tc) {
    
    cin >> N;

    vector<vector<int>> arr(N);
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        arr[i] = { a,b,i };
    }
    sort(arr.begin(), arr.end());

    pq<pii> q;

    for (int i = 0; i < N; i++) {
        q.push({ i,arr[i][2] });
        if (i != N - 1) nx[arr[i][2]].push_back(arr[i + 1][2]);
        swap(arr[i][0], arr[i][1]);
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < N; i++) {
        q.push({ i,arr[i][2] });
        if (i != N - 1) nx[arr[i][2]].push_back(arr[i + 1][2]);
    }

    while (!q.empty()) {
        auto [val, x] = q.top();
        q.pop();
        if (visited[x]) continue;
        visited[x] = true;
        ret[x] = val;
        for (int p : nx[x]) {
            if (visited[p]) continue;
            q.push({ val,p });
        }
    }

    for (int i = 0; i < N; i++) cout << ret[i] << endl;




    //cout << "Case #" << tc << ": " << debug << endl;
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