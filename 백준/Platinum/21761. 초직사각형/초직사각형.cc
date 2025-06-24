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


pq<ll> q[4]; 
ll arr[4]; 

bool cmp(pll a, pll b) {
    __int128 l = 1;
    __int128 r = 1;
    l = l * a.first * b.second;
    r = r * b.first * a.second;
    return l > r;
}

void solve(int tc) {
    
    int N, K;
    cin >> N >> K;
    
    for (int i = 0; i < 4; i++) {
        cin >> arr[i];
        q[i].push(0);
    }

    while (N--) {
        char t; ll u;
        cin >> t >> u;
        q[t - 'A'].push(u);
    }


    while (K--) {

        int idx = 0;

        for (int i = 1; i < 4; i++) {
            if (cmp(make_pair(q[i].top(), arr[i]), make_pair(q[idx].top(), arr[idx]))) idx = i;
        }

        cout << char('A' + idx) << " " << q[idx].top() << endl;

        arr[idx] += q[idx].top();
        q[idx].pop();

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