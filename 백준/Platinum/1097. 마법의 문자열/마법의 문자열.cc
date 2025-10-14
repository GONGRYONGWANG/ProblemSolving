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

vector<int> getPi(const string s) { // KMP 선행 작업, pattern->전이함수
    vector<int> pi(s.size(), 0);
    int j = 0;
    for (int i = 1; i < s.size(); i++) {
        while ((j > 0) && (s[i] != s[j])) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
            pi[i] = j;
        }
    }
    return pi;
}

vector<int> kmp(const string& s, const string& t, const vector<int>& pi) { //KMP, kmp(pattern, txt, pi)
    vector<int> result;
    int j = 0;
    for (int i = 0; i < t.size(); i++) {
        while ((j > 0) && (t[i] != s[j])) {
            j = pi[j - 1];
        }
        if (t[i] == s[j]) {
            if (j == s.size() - 1) {
                result.push_back(i - s.size() + 1);
                j = pi[j];
            }
            else {
                j++;
            }
        }
    }
    return result;
}

void solve(int tc) {
   
    int N;
    cin >> N;
    vector<pair<string,int>> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i].first;
    for (int i = 0; i < N; i++) arr[i].second = i;

    sort(arr.begin(), arr.end());

    int K; cin >> K;

    int ret = 0;
    do {
        string s;
        for (auto& [x, i] : arr) s += x;
        string txt = s + s;
        txt.pop_back();
        ret += (kmp(s, txt, getPi(s)).size() == K);

    } while (next_permutation(arr.begin(), arr.end()));

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