// template: https://github.com/GONGRYONGWANG/ProblemSolving/blob/main/template.txt
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
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


set<pii> cnt;
set<int> st[300001];
map<int,int> lefts;

void solve(int tc) {
    
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        st[x].insert(i);
    }

    for (int i = 1; i <= N; i++) {
        if (!st[i].empty()) {
            cnt.insert({ st[i].size(), i });
            lefts.insert({ *st[i].begin(), i });
        }
    }

    if (cnt.rbegin()->first > (N + 1) / 2) {
        cout << -1;
        return;
    }

    int cur = 0;
    while (N) {

        if (N % 2 && cnt.rbegin()->first == (N + 1) / 2) cur = cnt.rbegin()->second;
        else if (lefts.begin()->second != cur) cur = lefts.begin()->second;
        else cur = next(lefts.begin())->second;

        cout << *st[cur].begin() << " ";

        cnt.erase({ st[cur].size(), cur });
        lefts.erase(*st[cur].begin());
        st[cur].erase(st[cur].begin());
        if (!st[cur].empty()) lefts.insert({ *st[cur].begin(), cur });
        if (!st[cur].empty()) cnt.insert({ st[cur].size(), cur });

        N -= 1;
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