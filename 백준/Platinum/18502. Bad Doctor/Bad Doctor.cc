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

ll cost[500001];
pii lr[500001];
vector<int> arr[500001];

int cnt[500001];
vector<pii> line[500001];

int s[500001];
int A[500001];

void solve(int tc) {

    int N, M;
    cin >> N >> M;
    
    for (int i = 1; i <= M; i++) cin >> cost[i];

    vector<pii> v;
    for (int i = 1; i <= N; i++) {
        int l, r;
        cin >> l >> r;
        lr[i] = { l,r };
        int k; cin >> k;
        arr[i].resize(k);
        for (int& x : arr[i]) {
            cin >> x;
            v.push_back({ l,x });
            v.push_back({ r + 1,-x });
        }
    }

    sort(v.begin(), v.end());

    for (int i = 1; i <= M; i++) {
        s[i] = inf;
        A[i] = inf;
    }

    ll total = 0;


    for (auto& [idx, x] : v) {
        if (cnt[abs(x)] == 1) {
            line[abs(x)].push_back({ s[abs(x)], idx - 1 });
        }
        cnt[abs(x)] += x / abs(x);
        x = abs(x);
        if (cnt[x] == 1) {
            s[x] = idx;
        }
        if (cnt[x] != 0) A[x] = min(A[x], idx);
        else {
            total += cost[x] * (idx - A[x]);
            A[x] = inf;
        }
    }

    for(int i=1; i<=N;i++){
        ll ret = total;
        auto& [l, r] = lr[i];
        for (int x : arr[i]) {
            auto it = lower_bound(line[x].begin(), line[x].end(), make_pair( l,l ));
            while (it != line[x].end() && it->first <= r) {
                ret -= cost[x] * (min(r, it->second) - max(l, it->first) + 1);
                it++;
            }
        }
        cout << ret << " ";
    }

    // cout << "Case #" << tc << ": " << ret << endl;
}


int main() {
    //fin.open("input.txt"); fout.open("output.txt");
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}