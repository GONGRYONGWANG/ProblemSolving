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

void solve(int tc) {

    int N;
    cin >> N;

    string s;
    cin >> s;
    vector<int> arr;
    for (int i = 0; i < N - 1; i++) {
        if (s[i] != s[i + 1]) {
            arr.push_back(i);
        }
    }


    if (arr.size() == 0) {
        if (s.front() == 'W') cout << 0;
        else cout << -1;
        return;
    }


    if (arr.size() % 2) {
        if (s.front() == 'W') {
            if (arr.size() == 1) {
                cout << -1;
            }
            else {
                cout << arr.size() << endl;
                for (int i = 3; i < arr.size(); i++) cout << arr[i] + 1 << endl;
                cout << arr[2] + 1 << endl << arr[0] + 1 << endl << arr[1] + 1;
            }
        }
        else {
            cout << arr.size() << endl;
            for (int x : arr) cout << x + 1 << endl;
        }
        return;
    }

    cout << arr.size() << endl;
    if (s.front() == 'W') {
        for (int x : arr) cout << x + 1 << endl;
    }
    else {
        for (int i = 2; i < arr.size(); i++) cout << arr[i] + 1 << endl;
        cout << arr[1] + 1 << endl << arr[0] + 1;
    }




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