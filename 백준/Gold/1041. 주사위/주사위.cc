#pragma warning(disable:4996) 
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



int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    ll N;
    cin >> N;
    ll a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    vector<ll> v1 = { a,b,c,d,e,f };
    if (N == 1) {
        sort(v1.begin(), v1.end());
        cout << v1[0] + v1[1] + v1[2] + v1[3] + v1[4];
        return 0;
    }
    vector<ll> v2 = { a + b,a + c,a + d,a + e,b + c,c + e,e + d,d + b,f + b,f + c,f + d,f + e };
    vector<ll> v3 = { a + b + c,a + c + e,a + e + d,a + d + b,f + b + c,f + c + e,f + e + d,f + d + b };
    ll min1, min2, min3;
    min1 = min2 = min3 = 200;
    for (int i = 0; i < 6; i++) {
        min1 = min(min1, v1[i]);
    }
    for (int i = 0; i < 12; i++) {
        min2 = min(min2, v2[i]);
    }
    for (int i = 0; i < 8; i++) {
        min3 = min(min3, v3[i]);
    }
    cout << ((N - 2) * (N - 2) * 5 + (N - 2) * 4) * min1 + ((N - 2) * 8 + 4) * min2 + 4 * min3;

    return 0;
}