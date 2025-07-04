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

ll ans[200001];

void solve(int tc) {

    int N, Q;
    cin >> N >> Q;

    ll total = 0;
    vector<pll> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;
    for (int i = 0; i < N; i++) {
        total += arr[i].first;
        arr[i].first += arr[i].second;
    }
    sort(arr.begin(), arr.end());

    queue<tuple<int,int,int,int>> q; // s,e,l,r
    q.push({ 0,N, 0 ,N });
    while (!q.empty()) {
        queue<tuple<int, int, int, int>> nq;
        vector<pll> AC = arr;// {a+b,b}
        multiset<ll> WA; //b
        multiset<ll> NA; //b
        ll ret = total;

        int idx = 0;
        while (!q.empty()) {
            auto [s, e, l, r] = q.front();
            q.pop();
            if (s > e) continue;
            int k = (s + e) / 2;
            
            while (WA.size() < k) {
                if (NA.empty()) {
                    idx += 1;
                    ret -= AC.back().first;
                    ll x = AC.back().second;
                    WA.insert(x);
                    AC.pop_back();
                }
                else {
                    ll x = *NA.begin();
                    ret -= x;
                    WA.insert(x);
                    NA.erase(NA.find(x));
                }
            }

            int mxidx = idx;
            ll mx = ret;

            while (idx < r) {
                idx += 1;
                ret -= AC.back().first;
                WA.insert(AC.back().second);
                AC.pop_back();
                ll x = *WA.rbegin();
                ret += x;
                NA.insert(x);
                WA.erase(WA.find(x));
                if (ret > mx) {
                    mx = ret;
                    mxidx = idx;
                }
            }

            ans[k] = mx;

            nq.push({ s,k - 1,l,mxidx });
            nq.push({ k + 1,e,mxidx,r });
        }
        q = nq;
    }
    

    while (Q--) {
        int k;
        cin >> k;
        cout << ans[k] << endl;
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