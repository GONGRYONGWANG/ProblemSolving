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
#include<complex> // complex number
#include<numeric>
#include<cassert>
#include <climits>
#include <immintrin.h> // AVX, AVX2, AVX-512 // #pragma GCC optimize ("O3,unroll-loops") //#pragma GCC target ("avx,avx2,fma")
#include<chrono>
using namespace std;
using ll = long long;
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

#include<random> // rand
std::mt19937 gen;
void rng_init() {
    std::random_device rd;
    gen.seed(rd());  // main에서 1번
}
int randint(int l, int r) {
    std::uniform_int_distribution<int> dist(l, r);
    return dist(gen);
}

#include<fstream>
ifstream fin; ofstream fout;

//#define cin fin 
//#define cout fout

//int dx[4] = { -1,0,1,0 };
//int dy[4] = { 0,1,0,-1 };
//int dx8[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy8[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////


bool cal(string s) {
    bool ret = false;
    for (int i = 0; i < 9; i += 3) {
        ret |= (s[i] != '.' && s[i] == s[i + 1] && s[i] == s[i + 2]);
    }
    for (int i = 0; i < 3; i++) {
        ret |= (s[i] != '.' && s[i] == s[i + 3] && s[i] == s[i + 6]);
    }
    ret |= (s[0] != '.' && s[0] == s[4] && s[0] == s[8]);
    ret |= (s[2] != '.' && s[2] == s[4] && s[2] == s[6]);
    return ret;
}

void solve(int tc) {
    
    while (1) {
        string s;
        cin >> s;
        if (s == "end") break;
        int a = 0, b = 0;
        for (char x : s) {
            a += (x == 'X');
            b += (x == 'O');
        }

        if (a != b && a != b + 1) {
            cout << "invalid" << endl;
            continue;
        }

        if (a + b == 9 && !cal(s)) {
            cout << "valid" << endl;
            continue;
        }

        if (!cal(s)) {
            cout << "invalid" << endl;
            continue;
        }

        bool ret = false;
        for (int i = 0; i < 9; i++) {
            if (a == b && s[i] != 'O') continue;
            if (a == b + 1 && s[i] != 'X') continue;
            string ns = s;
            ns[i] = '.';
            ret |= !cal(ns);
        }

        if (ret) cout << "valid";
        else cout << "invalid";
        cout << endl;

    }






    // cout << "Case #" << tc << ": " << ret << endl;
}


int main() {
    //fin.open("input.txt"); fout.open("output.txt");
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    rng_init();
    int T = 1;
    //cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}