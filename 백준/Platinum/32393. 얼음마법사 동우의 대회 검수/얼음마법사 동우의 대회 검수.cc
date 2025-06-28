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

ll arr[100001];
ll testtime[100001];
unordered_set<int> heavytester[100001];
unordered_set<int> tests[100001];

void solve(int tc) {

    int N, M, Q;
    cin >> N >> M >> Q;

    vector<int> cnt(N + 1, 0);

    vector<vector<int>> query(Q);
    for (int i = 0; i < Q; i++) {
        int t;
        cin >> t;
        if (t == 3) {
            int x;
            cin >> x;
            query[i] = { t,x };
        }
        else {
            int x, y;
            cin >> x >> y;
            query[i] = { t,x,y };
            if (t == 1) cnt[y] += 1;
        }
    }

    for (int i = 0; i < Q; i++) {

        int t = query[i][0];
        if (t == 1) {
            int x = query[i][1];
            int y = query[i][2];
            if (cnt[y] >= 316) { // y is a heavytester
                if (!heavytester[x].count(y)) heavytester[x].insert(y);
                else heavytester[x].erase(y);
            }
            else { // y is not a heavytester
                if (!tests[y].count(x)) {
                    tests[y].insert(x);
                    arr[y] -= testtime[x];
                }
                else {
                    tests[y].erase(x);
                    arr[y] += testtime[x];
                }
            }
        }
        else if (t == 2) {
            int x = query[i][1];
            ll time = query[i][2];
            for (int ht : heavytester[x]) arr[ht] += time;
            testtime[x] += time;
        }
        else {
            int y = query[i][1];
            if (cnt[y] >= 316) { // y is a heavytester
                cout << arr[y] << endl;
            }
            else { // y is not a heavytester
                ll ret = arr[y];
                for (int test : tests[y])  ret += testtime[test];
                cout << ret << endl;
            }
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