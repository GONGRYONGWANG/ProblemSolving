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
const int inf = 1000000007;
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


ll ret[500001];
set<int> arr[1000001];
int val[500001];
set<int> solo;

void solve(int tc) {

    int Q;
    cin >> Q;

    int t = 0;
    int idx = 0;
    while (Q--) {
        int q;
        cin >> q;
        if (q == 1) {
            int x;
            cin >> x;
            idx += 1;
            val[idx] = x;
            if (arr[x].size() == 1) {
                ret[*arr[x].begin()] += t;
                solo.erase(x);
            }
            arr[x].insert(idx);
            if (arr[x].size() == 1) {
                ret[idx] -= t;
                solo.insert(x);
            }
        }
        else if (q == 2) {
            int k;
            cin >> k;
            int x = val[k];
            if (arr[x].size() == 1) {
                ret[k] += t;
                solo.erase(x);
            }
            arr[x].erase(k);
            if (arr[x].size() == 1) {
                ret[*arr[x].begin()] -= t;
                solo.insert(x);
            }
        }
        else {
            ll s;
            cin >> s;
            t += 1;
            if (solo.empty()) continue;
            int x = *solo.rbegin();
            ret[*arr[x].begin()] += s;
        }
    }

    for (int x : solo) {
        ret[*arr[x].begin()] += t;
    }

    for (int i = 1; i <= idx; i++) {
        cout << ret[i] << endl;
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