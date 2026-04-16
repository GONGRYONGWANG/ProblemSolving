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
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<ctime> // srand(time(0))
#include<regex> // 정규표현식
#include<random> // rand
#include<complex> // complex
#include<numeric>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef complex<double> cpx;
#define pq priority_queue
#define endl "\n"
#define inf 1e9
//int dx[4] = { 1,-1,0,0 };
//int dy[4] = { 0,0,1,-1 };
//int dx[8] = { 1,1,1,-1,-1,-1,0,0 };
//int dy[8] = { 1,0,-1,1,0,-1,1,-1 };
const double pi = 3.14159265358979323846;

int mod(string s, int p) {
    int ret = 0;
    for (int i = 0; i < s.length(); i++) {
        ret = (ret * 10 + (s[i] - '0')) % p;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

    string s;
    int K;
    cin >> s >> K;
    if (K == 2) {
        cout << "GOOD";
        return 0;
    }
    if (!mod(s, 2)){
        cout << "BAD"<<" "<<2;
        return 0;
    }
    for (int i = 3; i < K; i += 2) {
        if (!mod(s, i)) {
            cout << "BAD "<<i;
            return 0;
        }
    }
    cout << "GOOD";
    return 0;




    return 0;
}