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
const string debug = "output: ";
#define all(x) (x).begin(), (x).end()
#include<fstream>
ifstream fin; ofstream fout;


//int dx[4] = { 1,0,-1,0 };
//int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

bool cmp(vector<int>& a, vector<int>& b) {
    if (a[0] / 316 == b[0] / 316) return a[1] < b[1];
    return a[0] < b[0];
}

int arr[100001];
int cnt[100001];

void solve(int tc) {

    int N, Q;
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) cin >> arr[i];

    vector<vector<int>> query(Q);
    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        query[i] = { l,r,i };
    }
    sort(query.begin(), query.end(), cmp);

    vector<int> ans(Q);

    int s = 1; int e = 0;
    int ret = 0;

    for (int i = 0; i < Q; i++) {
        int l = query[i][0]; int r = query[i][1];
        while (e < r) {
            e += 1;
            cnt[arr[e]] += 1;
            if (cnt[arr[e]] == 3) ret += 1;
        }
        while (l < s) {
            s -= 1;
            cnt[arr[s]] += 1;
            if (cnt[arr[s]] == 3) ret += 1;
        }
        while (s < l) {
            cnt[arr[s]] -= 1;
            if (cnt[arr[s]] == 2) ret -= 1;
            s += 1;
        }
        while (r < e) {
            cnt[arr[e]] -= 1;
            if (cnt[arr[e]] == 2) ret -= 1;
            e -= 1;
        }
        ans[query[i][2]] = ret;
    }

    for (int x : ans) {
        cout << x << endl;
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