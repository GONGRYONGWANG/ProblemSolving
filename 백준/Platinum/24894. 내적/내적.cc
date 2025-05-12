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

vector<pll> arr;

ll get(int a, int b) {
    return arr[a].first * arr[b].first + arr[a].second * arr[b].second;
}

ll dnq(int s, int e, int l, int r) {
    l = max(0,l);
    r = min(r, int(arr.size())-1);
    if(l==r){
        l = max(0,l-1);
        r = min(int(arr.size())-1, r+1);
    }
    if (e < s) return 0;
    int m = (s + e) / 2;

    int idx = -1;
    for (int i = l; i <= r; i++) {
        if (i == m) continue;
        if (idx == -1 || get(m, idx) < get(m, i)) idx = i;
    }

    ll ret = get(m, idx);
    ret = max(ret, dnq(s, m - 1, l, idx + 1));
    ret = max(ret, dnq(m + 1, e, idx - 1, r));
    return ret;

}

void solve(int tc) {

    int N;
    cin >> N;

    vector<pll> init(N);
    for (int i = 0; i < N; i++) cin >> init[i].first >> init[i].second;

    sort(init.begin(), init.end());

    ll ans = 0;

    for (pll& p : init) {
        while (!arr.empty() && arr.back().second <= p.second) {
            ans = max(ans, arr.back().first * p.first + arr.back().second * p.second);
            arr.pop_back();
        }
        arr.push_back(p);
    }
    
    if(arr.size()==1){
        cout<<ans;
        return;
    }
    
    ans = max(ans, dnq(0, arr.size() - 1, 0, arr.size() - 1));

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