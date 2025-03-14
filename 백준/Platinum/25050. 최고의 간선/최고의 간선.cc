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

vector<vector<ll>> E[2001];

struct cmp {
    bool operator()(vector<ll>& a, vector<ll>& b) {
        return a[1] > b[1];
    }
};

void solve(int tc) {
    
    int N, M;
    cin >> N >> M;
    
    for (int i = 1; i <= M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        E[u].push_back({ v,w,i });
    }

    vector<int> ret(M + 1, 0);

    for (int i = 1; i <= N; i++) {
        pq<vector<ll>, vector<vector<ll>>, cmp > q;
        vector<bool> visited(N + 1, false);
        vector<int> cnt(M + 1, 0);
        vector<int> prev(M + 1, 0);
        stack<int> st;
        q.push({ i,0,0,0 }); // x, d, idx, prv
        while (!q.empty()) {
            int x = q.top()[0];
            ll d = q.top()[1];
            int idx = q.top()[2];
            int prv = q.top()[3];
            q.pop();
            if (visited[x]) continue;
            visited[x] = true;
            cnt[idx] += 1;
            prev[idx] = prv;
            st.push(idx);
            for (vector<ll>& e : E[x]) {
                if (visited[e[0]]) continue;
                q.push({ e[0], d + e[1],e[2], idx });
            }
        }

        while (!st.empty()) {
            ret[st.top()] += cnt[st.top()];
            cnt[prev[st.top()]] += cnt[st.top()];
            st.pop();
        }


    }

    vector<int> ans = { 1 };
    for (int i = 2; i <= M; i++) {
        if (ret[ans.front()] < ret[i]) {
            ans.clear();
            ans = { i };
        }
        else if (ret[ans.front()] == ret[i]) ans.push_back(i);
    }

    cout << ans.size() << endl;
    for (int x : ans) cout << x << " ";

    



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