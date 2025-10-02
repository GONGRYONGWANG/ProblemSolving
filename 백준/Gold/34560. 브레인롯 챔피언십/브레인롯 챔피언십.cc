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


int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////

vector<int> E[3000];
int ind[3000];

void solve(int tc) {
    
    int N;
    cin >> N;
    vector<string> name(N);
    vector<vector<int>> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> name[i];
        int a, b, c;
        cin >> a >> b >> c;
        arr[i] = { a,b,c };
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int cnt = 0;
            for (int k = 0; k < 3; k++) {
                if (arr[i][k] > arr[j][k]) cnt += 1;
                if (arr[i][k] < arr[j][k]) cnt -= 1;
            }
            if (cnt > 0) {
                E[i].push_back(j);
                ind[j] += 1;
            }
        }
    }

    vector<string> ans;
    queue<int> q;
    for (int i = 0; i < N; i++) {
        if (ind[i] == 0) {
            q.push(i);
            ans.push_back(name[i]);
        }
    }

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int nx : E[x]) {
            ind[nx] -= 1;
            if (ind[nx] == 0) q.push(nx);
        }
    }

    for (int i = 0; i < N; i++) {
        if (ind[i]) {
            cout << "Paradoxe Absurdo";
            return;
        }
    }

    sort(ans.begin(), ans.end());
    for (string& s : ans) {
        cout << s << endl;
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