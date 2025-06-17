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


int arr[200001];
bool inst[200001];

void solve(int tc) {

    int N, M, Q;
    cin >> N >> M >> Q;
    for (int i = 1; i <= N; i++) cin >> arr[i];

    vector<int> l(M), r(M);
    for (int i = 0; i < M; i++) cin >> l[i];
    for (int i = 0; i < M; i++) cin >> r[i];
    sort(l.begin(), l.end()); sort(r.begin(), r.end());

    for (int i = 0; i < M; i++) {
        if (l[i] > r[i]) {
            while (Q--) {
                int a, b;
                cin >> a >> b;
                cout << int(1e9) << endl;
            }
            return;
        }

        if (i != 0) l[i] = max(l[i], r[i - 1] + 1);

        for (int j = l[i]; j <= r[i]; j++) inst[j] = true;
    }

    multiset<int> st;
    for (int i = 1; i <= N; i++) {
        if (inst[i]) st.insert(arr[i]);
    }

    while (Q--) {
        int a, b;
        cin >> a >> b;
        if (a != b) {
            if (inst[a]) st.erase(st.find(arr[a]));
            if (inst[b]) st.erase(st.find(arr[b]));
            swap(arr[a], arr[b]);
            if (inst[a]) st.insert(arr[a]);
            if (inst[b]) st.insert(arr[b]);
        }
        cout << *st.rbegin() << endl;
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