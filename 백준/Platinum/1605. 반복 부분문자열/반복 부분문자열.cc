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
#define INF 1e18+7
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

int pow26mod1[200000];
int pow26mod2[200000];
int mod1 = 814841;
int mod2 = 592351;

void solve(int tc) {

    int N;
    cin >> N;
    
    pow26mod1[0] = pow26mod2[0] = 1;
    for (int i = 1; i < N; i++) {
        pow26mod1[i] = pow26mod1[i - 1] * 26 % mod1;
        pow26mod2[i] = pow26mod2[i - 1] * 26 % mod2;
    }

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        char x;
        cin >> x;
        arr[i] = x - 'a';
    }

    int l = 0;
    int r = N;
    while (l < r) {
        int m = (l + r + 1) / 2;

        unordered_map<int, vector<int>> table;

        int h1 = 0;
        int h2 = 0;
        for (int i = 0; i < m; i++) {
            h1 = (h1 * 26 + arr[i]) % mod1;
            h2 = (h2 * 26 + arr[i]) % mod2;
        }
        table[h1].push_back(h2);

        bool flag = false;
        for (int i = m; i < N; i++) {
            h1 += mod1 - arr[i - m] * pow26mod1[m - 1] % mod1;
            h1 %= mod1;
            h1 = (h1 * 26 + arr[i]) % mod1;
            h2 += mod2 - arr[i - m] * pow26mod2[m - 1] % mod2;
            h2 %= mod2;
            h2 = (h2 * 26 + arr[i]) % mod2;

            if (table.count(h1)) {
                for (int x : table[h1]) {
                    if (x == h2) flag = true;
                }
            }

            if (flag) break;

            table[h1].push_back(h2);
        }

        if (flag) l = m;
        else r = m - 1;


    }


    cout << l;





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