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

///////////////////////////////////////////////////////////////




void solve(int tc) {
    
    int a = 0, b = 0;
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1') a += (1 << (s.length() - 1 - i));
    }
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1') b += (1 << (s.length() - 1 - i));
    }

    vector<int> visited((1 << 10), 0);

    queue<int> q;
    q.push(a);
    visited[a] = 1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (x != (1 << 10) - 1 && !visited[x + 1]) {
            visited[x + 1] = visited[x] + 1;
            q.push(x + 1);
        }
        if (x != 0 && !visited[x - 1]) {
            visited[x - 1] = visited[x] + 1;
            q.push(x - 1);
        }
        for (int i = 0; i < 10; i++) {
            if (x / (1 << i) <= 1) continue;
            if (visited[x ^ (1 << i)]) continue;
            visited[x ^ (1 << i)] = visited[x] + 1;
            q.push(x ^ (1 << i));
        }
    }

    cout << visited[b] - 1;




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