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
const ll INF = 1e18 + 7;
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
    vector<pll> arr1(N);
    vector<pll> arr2(N);
    multiset<ll> L, R;
    multiset<ll> B, T;
    for (int i = 0; i < N; i++) {
        cin >> arr1[i].first >> arr1[i].second;
        arr2[i] = arr1[i];
        swap(arr2[i].first, arr2[i].second);
        R.insert(arr1[i].second);
        T.insert(arr1[i].first);
    }
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    ll ans = (arr1[N - 1].first - arr1[0].first) * (arr2[N - 1].first - arr2[0].first);

    for (int i = 0; i < N - 1; i++) {
        ll x = arr1[i].first; ll y = arr1[i].second;
        L.insert(y); R.erase(R.find(y));
        
        ll ret = INF;
        if (arr1[i + 1].first != x) ret = ((x - arr1[0].first) * (*L.rbegin() - *L.begin()))
            + ((arr1[N - 1].first - arr1[i + 1].first) * (*R.rbegin() - *R.begin()));

        ans = min(ans, ret);

        x = arr2[i].second; y = arr2[i].first;
        B.insert(x); T.erase(T.find(x));

        if (arr2[i + 1].first != y) ret = ((y - arr2[0].first) * (*B.rbegin() - *B.begin()))
            + ((arr2[N - 1].first - arr2[i + 1].first) * (*T.rbegin() - *T.begin()));

        ans = min(ans, ret);
    }





    cout << (arr1[N - 1].first - arr1[0].first) * (arr2[N - 1].first - arr2[0].first) - ans;




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