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


//int dx[4] = { 1,0,-1,0 };
//int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////



void solve(int tc) {
    

    int N;
    cin >> N;
    pq<ll, vector<ll>, less<ll>> L;
    pq<ll, vector<ll>, greater<ll>> R;

    ll Xtotal = 0;

    ll Ltotal = 0, Rtotal = 0;
    while (N--) {
        ll x, y;
        cin >> x >> y;
        Xtotal += abs(x);
        L.push(y);
        Ltotal += y;
        while (L.size() > R.size() + 1) {
            R.push(L.top());
            Rtotal += L.top();
            Ltotal -= L.top();
            L.pop();
        }

        while (!R.empty() && L.top() > R.top()) {
            Ltotal -= L.top();
            Rtotal -= R.top();
            L.push(R.top());
            Ltotal += R.top();
            R.push(L.top());
            Rtotal += L.top();
            L.pop();
            R.pop();
        }

        cout << L.top() << " " << Xtotal + L.top() * L.size() - Ltotal + Rtotal - L.top() * R.size() << endl;

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