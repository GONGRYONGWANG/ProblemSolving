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
const ll INF = 1e18 + 7;
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

void solve(int tc) {

    int N;
    cin >> N;
    for (int i = pow(3, N - 1) - 1; i >= 0; i--) {
        int x = i;
        ll ret = 0;
        ll cur = 1;
        vector<int> v(N - 1);
        for (int j = 0; j < N - 1; j++) {
            v[j] = x % 3;
            x /= 3;
        }
        reverse(v.begin(), v.end());
        for (int j = 2; j <= N; j++) {
            if (v[j - 2] == 2) {
                cur *= 10; 
                if (cur < 0) cur -= j;
                else cur += j;
            }
            else if (v[j - 2] == 1) {
                ret += cur;
                cur = j;
            }
            else {
                ret += cur;
                cur = -j;
            }
        }
        ret += cur;
        if (ret == 0) {
            cout << 1;
            for (int j = 2; j <= N; j++) {
                if (v[j - 2] == 2) cout << " ";
                else if (v[j - 2] == 1) cout << "+";
                else cout << "-";
                cout << j;
            }
            cout << endl;
        }
    }
    cout << endl;




}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    cin >> T;
    //fin.open("input.txt"); fout.open("output.txt");
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}