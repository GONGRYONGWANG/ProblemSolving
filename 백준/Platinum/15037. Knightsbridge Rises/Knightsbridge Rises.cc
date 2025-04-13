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
#define INF ll(9e18)
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
    vector<vector<int>> arr;
    for (int i = 1; i <= N; i++) {
        int w, l;
        cin >> w >> l;
        if (w >= l) continue;
        arr.push_back({ l, w, i });
    }
    sort(arr.begin(), arr.end());


    int M;
    cin >> M;
    vector<int> T(M);
    for (int i = 0; i < M; i++) cin >> T[i];

    vector<stack<int>> ret(M);
    for (int i = 0; i < M; i++) {
        map<int, int> m;
        m[0] = -1;
        for (int i = 0; i < arr.size(); i++) {
            int w = arr[i][1]; int l = arr[i][0]; 
            auto it = m.lower_bound(w);
            if (it == m.end() || it->first == l) continue;
            m[l] = i;
        }
        auto it = m.lower_bound(T[i]);
        if (it == m.end()) {
            cout << "impossible";
            return;
        }

        while (it->second != -1) {
            ret[i].push(arr[it->second][2]);
            T[i] = arr[it->second][1];
            arr[it->second][1] = inf;
            it = m.lower_bound(T[i]);
        }

    }

    for (int i = 0; i < M; i++) {
        while (!ret[i].empty()) {
            cout << ret[i].top() << " ";
            ret[i].pop();
        }
        cout << endl;
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