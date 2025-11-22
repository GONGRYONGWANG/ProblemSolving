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
const long double pi = acosl(-1);
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

int arr[1001];
bool visited[1001];

void solve(int tc) {

    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];

    vector<vector<int>> v;
    for (int i = 1; i <= N; i++) {
        if (visited[i]) continue;
        visited[i] = true;
        if (i == arr[i]) continue;

        v.push_back({ i });
        int x = arr[i];
        while (x != i) {
            visited[x] = true;
            v.back().push_back(x);
            x = arr[x];
        }
    }

    if (v.size() <= 1) {
        cout << v.size() << endl;
        for (int i = 0; i < v.size(); i++) {
            cout << v[i].size() << ":";
            for (int x : v[i]) cout << " " << x;
            cout << endl;
        }
        return;
    }

    cout << 2 << endl;
    int total = 0;
    for (int i = 0; i < v.size(); i++) {
        total += v[i].size();
    }
    cout << total << ":";
    for (int i = 0; i < v.size(); i++) {
        for (int x : v[i]) cout << " " << x;
    }
    cout << endl;
    cout << v.size() << ":";
    for (int i = v.size() - 1; i >= 0; i--) {
        cout << " " << v[i].front();
    }



    // cout << "Case #" << tc << ": " << ret << endl;
}


int main() {
    // fin.open("input.txt"); fout.open("output.txt");
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}