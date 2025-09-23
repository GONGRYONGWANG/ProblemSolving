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


//int dx[4] = { -1,0,1,0 };
//int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////


pii tree[4000004];
void update(int node, int start, int end, int x, int v) {
    if (x > end || x < start) return;
    if (start == end) {
        tree[node].first += v;
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, x, v);
    update(node * 2 + 1, mid + 1, end, x, v);
    vector<int> tmp = { tree[node * 2].first,tree[node * 2].second, tree[node * 2 + 1].first, tree[node * 2 + 1].second };
    sort(tmp.rbegin(), tmp.rend());
    tree[node] = { tmp[0], tmp[1] };
}

int N;
vector<int> arr[300000];
int get() {

    vector<vector<pii>> A(1000002);

    for (int i = 1; i < 4000004; i++) {
        tree[i] = { 0,0 };
    }

    vector<int> sum(1000002, 0);
    for (int i = 0; i < N; i++) {
        A[arr[i][0]].push_back({ arr[i][1],arr[i][2] });
        sum[arr[i][1]] += arr[i][2];
    }

    for (int i = 1; i <= 1000001; i++) {
        if (sum[i] != 0) update(1, 1, 1000001, i, sum[i]);
    }

    sort(sum.rbegin(), sum.rend());
    int mx = sum[0] + sum[1] + sum[2];

    for (int i = 1; i <= 1000001; i++) {
        int ret = 0;
        for (auto& [x, v] : A[i]) {
            ret += v;
            update(1, 1, 1000001, x, -v);
        }
        mx = max(mx, ret + tree[1].first + tree[1].second);
        for (auto& [x, v] : A[i]) {
            update(1, 1, 1000001, x, v);
        }
    }

    return mx;
}

void solve(int tc) {
   
    
    cin >> N;

    for (int i = 0; i < N; i++) {
        int x, y, v;
        cin >> x >> y >> v;
        x += 1; y += 1;
        arr[i] = { x,y,v };
    }

    int ans = get();
    for (int i = 0; i < N; i++) swap(arr[i][0], arr[i][1]);
    ans = max(ans, get());
    cout << ans;

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