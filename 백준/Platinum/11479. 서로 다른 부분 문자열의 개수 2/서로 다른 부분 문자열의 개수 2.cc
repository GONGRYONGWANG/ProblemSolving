// template: https://github.com/GONGRYONGWANG/ProblemSolving/blob/main/template.txt
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
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
vector<int> build_suffix_array(const string& s) { // Suffix Array (SA) O(NlogN)
    int n = s.size();
    const int ALPHABET = 256;

    vector<int> sa(n), rank(n), tmp(n), cnt(max(ALPHABET, n));

    for (int i = 0; i < n; i++) {
        sa[i] = i;
        rank[i] = s[i];
    }

    for (int k = 1; k < n; k <<= 1) {
        auto cmp = [&](int i, int j) {
            if (rank[i] != rank[j]) return rank[i] < rank[j];
            int ri = (i + k < n) ? rank[i + k] : -1;
            int rj = (j + k < n) ? rank[j + k] : -1;
            return ri < rj;
        };

        sort(sa.begin(), sa.end(), cmp);

        tmp[sa[0]] = 0;
        for (int i = 1; i < n; i++)
            tmp[sa[i]] = tmp[sa[i - 1]] + cmp(sa[i - 1], sa[i]);

        rank = tmp;
    }

    return sa;
}

vector<int> build_lcp_array(const string& s, const vector<int>& sa) {
    int n = s.size();
    vector<int> rank(n), lcp(n - 1);

    // sa[i]의 순서를 rank[sa[i]] = i로 저장
    for (int i = 0; i < n; i++)
        rank[sa[i]] = i;

    int h = 0;
    for (int i = 0; i < n; i++) {
        if (rank[i] == 0) continue; // 첫 번째 접미사는 비교할 이전 접미사가 없음
        int j = sa[rank[i] - 1];

        // s[i+h]와 s[j+h]가 같은 동안 h를 증가
        while (i + h < n && j + h < n && s[i + h] == s[j + h])
            h++;

        lcp[rank[i] - 1] = h;

        if (h > 0) h--; // 다음 비교를 위해 h 감소 (최적화)
    }

    return lcp;
}

///////////////////////////////////////////////////////////////

void solve(int tc) {

    string s;
    cin >> s;
    vector<int> SA = build_suffix_array(s);
    vector<int> LCP = build_lcp_array(s, SA);

    
    ll ans = s.length() - SA[0];
    for (int i = 1; i < s.length(); i++) {
        ans += s.length() - SA[i] - LCP[i-1];
    }

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