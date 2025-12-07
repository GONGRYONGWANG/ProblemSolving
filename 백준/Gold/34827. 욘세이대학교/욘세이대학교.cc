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
const long double pi = acosl(-1);
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




void solve(int tc) {

    int N;
    cin >> N;
    vector<bool> visited(26, false);

    string s;
    cin >> s;
    for (char x : s) {
        visited[x - 'A'] = true;
    }

    int total = 0;
    for (int i = 0; i < N - 1; i++) {
        if (s[i] < s[i + 1]) total += 1;
        else total -= 1;
    }

    if (total > 1) {
        char x = s.back();
        int cnt = 0;
        for (int i = x - 'A'; i >= 0; i--) {
            cnt += !visited[i];
        }
        if (total - cnt <= 1) {
            for (int i = x - 'A'; i >= 0; i--) {
                if (visited[i]) continue;
                s.push_back(char('A' + i));
                total -= 1;
                if (total <= 1) break;
            }
        }
        else {
            total += 2;
            for (int i = 25; i >= 0; i--) {
                if (visited[i]) continue;
                s.push_back(char('A' + i));
                total -= 1;
                if (total <= 1) break;
            }
        }
    }
    else if (total < -1) {
        char x = s.back();
        int cnt = 0;
        for (int i = x - 'A'; i < 26; i++) {
            cnt += !visited[i];
        }
        if (total + cnt >= -1) {
            for (int i = x - 'A'; i < 26; i++) {
                if (visited[i]) continue;
                s.push_back(char('A' + i));
                total += 1;
                if (total >= -1) break;
            }
        }
        else {
            total -= 2;
            for (int i = 0; i < 26; i++) {
                if (visited[i]) continue;
                s.push_back(char('A' + i));
                total += 1;
                if (total >= -1) break;
            }
        }
    }

    cout << s.length() << endl << s;




    // cout << "Case #" << tc << ": " << ret << endl;
}


int main() {
    // fin.open("input.txt"); fout.open("output.txt");
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}