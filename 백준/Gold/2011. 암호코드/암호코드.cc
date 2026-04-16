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

string s;
ll DP[5000];
ll dp(int x) {
    if (x == s.length()) return 1;
    if (DP[x] != -1) return DP[x];
    if (s[x] == '0') return 0;
    if (x == s.length() - 1) return 1;
    if (s[x] >= '3') return DP[x] = dp(x + 1);
    if (s[x] == '2' && s[x + 1] > '6') return DP[x] = dp(x+1);
    return DP[x] = (dp(x + 1) + dp(x + 2))%1000000;
}
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> s;
    fill(DP, DP + s.length(), -1);
    cout << dp(0);


    return 0;
}