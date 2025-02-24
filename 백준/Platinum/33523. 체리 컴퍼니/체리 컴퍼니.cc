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

int arr[300001];
int cnt[300001];
int bck[548];

void solve(int tc) {

    int N;
    cin >> N;
    int sqrtN = sqrt(N);
    for (int i = 2; i <= N; i++) cin >> arr[i];

    int Q;
    cin >> Q;
    vector<vector<int>> query(Q);

    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        query[i] = { l,r,i };
    }

    auto cmp = [&](vector<int> & q1, vector<int> & q2) {
        if (q1[0] / sqrtN == q2[0] / sqrtN) {
            return q1[1] < q2[1];
        }
        return q1[0] < q2[0];
    };
    sort(query.begin(), query.end(), cmp);

    vector<int> ans(Q);

    int s = 1; int e = 1;
    for (int i = 0; i < Q; i++) {
        int l = query[i][0];
        int r = query[i][1] + 1;

        while (l < s) {
            s -= 1;
            cnt[arr[s]] += 1;
            bck[arr[s] / sqrtN] += 1;
        }
        while (e < r) {
            cnt[arr[e]] += 1;
            bck[arr[e] / sqrtN] += 1;
            e += 1;
        }
        while (s < l) {
            cnt[arr[s]] -= 1;
            bck[arr[s] / sqrtN] -= 1;
            s += 1;
        }
        while (r < e) {
            e -= 1;
            cnt[arr[e]] -= 1;
            bck[arr[e] / sqrtN] -= 1;
        }

        int ret = 0;
        int lbck = l / sqrtN; int rbck = r / sqrtN;
        if (lbck == rbck) {
            for (int j = l; j < r; j++) {
                ret += cnt[j];
            }
        }
        else {
            for (int j = lbck + 1; j < rbck; j++) {
                ret += bck[j];
            }
            for (int j = l; j < (lbck + 1) * sqrtN; j++) {
                ret += cnt[j];
            }
            for (int j = rbck * sqrtN; j < r; j++) {
                ret += cnt[j];
            }
        }

        ans[query[i][2]] = r - l - ret;

    }

    for (int x : ans) cout << x << endl;




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