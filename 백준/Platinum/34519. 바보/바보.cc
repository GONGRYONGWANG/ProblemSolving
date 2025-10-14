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
//#define cin fin 
//#define cout fout

//int dx[4] = { -1,0,1,0 };
//int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////

int N;
int T[400000];
int arr[400000];
bool visited[400000];

void update(int x) {
    if (x != 0) arr[x] = min(arr[x], arr[x - 1] + T[x] / 2);
    if (x != N - 1) arr[x] = min(arr[x], arr[x + 1] + T[x] / 2);
    if (x != 0 && x != N - 1) arr[x] = min(arr[x], max(arr[x - 1] , arr[x + 1]) + T[x] / 4);
}

void solve(int tc) {
   
    cin >> N;

    set<pii> st;
    for (int i = 0; i < N; i++) {
        cin >> T[i];
        arr[i] = T[i];
        st.insert({ arr[i],i });
    }

    int ret = 0;
    while (!st.empty()) {
        auto [x, i] = *st.begin();
        ret = max(ret, x);
        st.erase(st.begin());
        visited[i] = true;
        if (i != 0 && !visited[i - 1]) {
            st.erase({ arr[i - 1],i - 1 });
            update(i - 1);
            st.insert({ arr[i - 1],i - 1 });
        }
        if (i != N - 1 && !visited[i + 1]) {
            st.erase({ arr[i + 1],i + 1 });
            update(i + 1);
            st.insert({ arr[i + 1],i + 1 });
        }
    }

    cout << ret;




    //cout << "Case #" << tc << ": " << debug << endl;
}


int main() {
    //fin.open("input.txt"); fout.open("output.txt");
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}