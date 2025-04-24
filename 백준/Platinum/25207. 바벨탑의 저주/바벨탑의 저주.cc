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


int arr[500001];
vector<int> child[500001];
deque<int>* q[500001];
bool isp[500001];

bool ispalindrom(int x) {
    if (child[x].empty()) return true;
    int n = child[x].size();
    if (n % 2 && !isp[child[x][n / 2]]) return false;
    unordered_map<int, int> m;
    for (int i = 0; i < n / 2; i++) {
        if (q[child[x][i]]->size() != q[child[x][n - 1 - i]]->size()) return false;
        for (int j = 0; j < q[child[x][i]]->size(); j++) {
            int a = (*q[child[x][i]])[j];
            int b = (*q[child[x][n - 1 - i]])[q[child[x][i]]->size() - 1 - j];
            if (arr[a] != arr[b]) return false;
            if (!m.count(a)) m[a] = b;
            else if (m[a] != b) return false;
            m[a] = b;
        }
    }
    return true;
}

void concat(int x) {
    if (child[x].empty()) {
        q[x] = new deque<int>;
        q[x]->push_back(x);
        q[x]->push_front(x);
        return;
    }

    int n = child[x].size();

    int idx = 0;
    for (int i = 0; i < n; i++) {
        if (q[child[x][i]]->size() > q[child[x][idx]]->size()) {
            idx = i;
        }
    }

    q[x] = q[child[x][idx]];
    for (int i = idx + 1; i < n; i++) {
        q[x]->push_back(x);
        for (auto it = q[child[x][i]]->begin(); it != q[child[x][i]]->end(); it++) q[x]->push_back(*it);
    }
    q[x]->push_back(x);

    for (int i = idx - 1; i >= 0; i--) {
        q[x]->push_front(x);
        for (auto it = q[child[x][i]]->rbegin(); it != q[child[x][i]]->rend(); it++) {
            q[x]->push_front(*it);
        }
    }
    q[x]->push_front(x);

}

void dfs(int x) {
    for (int nx : child[x]) {
        dfs(nx);
    }
    isp[x] = ispalindrom(x);
    concat(x);
}

void solve(int tc) {

    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        child[a].push_back(b);
    }

    for (int i = 1; i <= N; i++) {
        sort(child[i].begin(), child[i].end());
    }

    dfs(1);

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += isp[i];
    }

    cout << ans << endl;
    for (int i = 1; i <= N; i++) {
        if (isp[i]) cout << i << " ";
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