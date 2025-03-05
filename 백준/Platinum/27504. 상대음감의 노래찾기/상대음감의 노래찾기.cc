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
vector<int> getPi(const vector<int>& pattern) { // 수열용 KMP 선행작업
    vector<int> pi(pattern.size(), 0);
    int j = 0;
    for (int i = 1; i < pattern.size(); i++) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = pi[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            j++;
            pi[i] = j;
        }
    }
    return pi;
}

vector<int> kmp(const vector<int>& pattern, const vector<int>& text, const vector<int>& pi) { // 수열용 KMP
    vector<int> result;
    int j = 0;
    for (int i = 0; i < text.size(); i++) {
        while (j > 0 && text[i] != pattern[j]) {
            j = pi[j - 1];
        }
        if (text[i] == pattern[j]) {
            if (j == pattern.size() - 1) {
                result.push_back(i - pattern.size() + 1);
                j = pi[j];
            }
            else {
                j++;
            }
        }
    }
    return result;
}
///////////////////////////////////////////////////////////////


void solve(int tc) {
    int N;
    cin >> N;
    vector<vector<int>> txt(N + 1);

    for (int i = 1; i <= N; i++) {
        int K;
        cin >> K;
        vector<int> arr(K);
        for (int& x : arr)cin >> x;
        txt[i].resize(K - 1);
        for (int j = 0; j < arr.size() - 1; j++) {
            txt[i][j] = arr[j + 1] - arr[j];
        }
    }

    int L;
    cin >> L;
    vector<int> parr(L);
    for (int& x : parr) cin >> x;
    vector<int> pattern(L - 1);
    for (int i = 0; i < L - 1; i++) {
        pattern[i] = parr[i + 1] - parr[i];
    }
    vector<int> pi = getPi(pattern);
    
    bool b = false;
    for (int i = 1; i <= N; i++) {
        if (!kmp(pattern, txt[i], pi).empty()) {
            cout << i << " ";
            b = true;
        }
    }
    if (!b) cout << -1;


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