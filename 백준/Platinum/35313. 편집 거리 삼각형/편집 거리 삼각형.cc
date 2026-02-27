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
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////

ull modinv_64(ull x) {
    ull ret = x;
    for (int i = 0; i < 6; i++) {
        ret *= (ull)2 - x * ret;
    }
    return ret;
}
uint modinv_32(uint x) {
    uint ret = x;
    for (int i = 0; i < 5; i++) {
        ret *= (uint)2 - x * ret;
    }
    return ret;
}

ull pow1[5010];
uint pow2[5010];

ull psumA_1[5001];
uint psumA_2[5001];

ull psumB_1[5001];
uint psumB_2[5001];

void solve(int tc) {

    int p = 998244351;
    ull invp_1 = modinv_64(p);
    uint invp_2 = modinv_32(p);

    pow1[0] = pow2[0] = 1;
    for (int i = 1; i < 5010; i++) {
        pow1[i] = pow1[i - 1] * p;
        pow2[i] = pow2[i - 1] * p;
    }

    int N, M;
    cin >> N >> M;

    string s, t;
    cin >> s >> t;

    for (int i = 1; i <= N; i++) {
        psumA_1[i] = psumA_1[i - 1] + pow1[i] * (s[i - 1] - 'A');
        psumA_2[i] = psumA_2[i - 1] + pow2[i] * (s[i - 1] - 'A');
    }

    for (int i = 1; i <= M; i++) {
        psumB_1[i] = psumB_1[i - 1] + pow1[i] * (t[i - 1] - 'A');
        psumB_2[i] = psumB_2[i - 1] + pow2[i] * (t[i - 1] - 'A');
    }

    set<tuple<int, ull, uint>> st;

    for (int i = 1; i <= N + 1; i++) {
        for (int j = 0; j < 26; j++) {
            ull hash1 = (psumA_1[N] - psumA_1[i - 1]) * p + pow1[i] * j + psumA_1[i - 1];
            uint hash2 = (psumA_2[N] - psumA_2[i - 1]) * p + pow2[i] * j + psumA_2[i - 1];
            st.insert({ N + 1,hash1,hash2 });
        }
    }

    for (int i = 1; i <= N; i++) {
        ull hash1 = (psumA_1[N] - psumA_1[i]) * invp_1 + psumA_1[i - 1];
        uint hash2 = (psumA_2[N] - psumA_2[i]) * invp_2 + psumA_2[i - 1];
        st.insert({ N - 1,hash1,hash2 });
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 26; j++) {
            if (j == (s[i - 1] - 'A')) continue;
            ull hash1 = psumA_1[N] - psumA_1[i] + pow1[i] * j + psumA_1[i - 1];
            uint hash2 = psumA_2[N] - psumA_2[i] + pow2[i] * j + psumA_2[i - 1];
            st.insert({ N,hash1,hash2 });
        }
    }


    for (int i = 1; i <= M + 1; i++) {
        for (int j = 0; j < 26; j++) {
            ull hash1 = (psumB_1[M] - psumB_1[i - 1]) * p + pow1[i] * j + psumB_1[i - 1];
            uint hash2 = (psumB_2[M] - psumB_2[i - 1]) * p + pow2[i] * j + psumB_2[i - 1];
            if (st.count({ M + 1,hash1,hash2 })) {
                cout << 1 << endl;
                for (int k = 0; k < M; k++) {
                    if (k == i - 1) cout << char('A' + j);
                    cout << t[k];
                }
                if (i == M + 1) cout << char('A' + j);
                return;
            }
        }
    }

    for (int i = 1; i <= M; i++) {
        ull hash1 = (psumB_1[M] - psumB_1[i]) * invp_1 + psumB_1[i - 1];
        uint hash2 = (psumB_2[M] - psumB_2[i]) * invp_2 + psumB_2[i - 1];
        if (st.count({ M - 1,hash1,hash2 })) {
            cout << 1 << endl;
            for (int k = 0; k < M; k++) {
                if (k == i - 1) continue;
                else cout << t[k];
            }
            return;
        }
    }

    for (int i = 1; i <= M; i++) {
        for (int j = 0; j < 26; j++) {
            if (j == (t[i - 1] - 'A')) continue;
            ull hash1 = psumB_1[M] - psumB_1[i] + pow1[i] * j + psumB_1[i - 1];
            uint hash2 = psumB_2[M] - psumB_2[i] + pow2[i] * j + psumB_2[i - 1];
            if (st.count({ M,hash1,hash2 })) {
                cout << 1 << endl;
                for (int k = 0; k < M; k++) {
                    if (k == i - 1) cout << char('A' + j);
                    else cout << t[k];
                }
                return;
            }
        }
    }

    cout << 0;



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