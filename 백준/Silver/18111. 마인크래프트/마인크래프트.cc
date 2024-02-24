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


int cnt[257];
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N, M;
    ll B;
    cin >> N >> M >> B;
    for (int i = 0; i < N * M; i++) {
        int x;
        cin >> x;
        cnt[x] += 1;
        B += x;
    }

    int height;
    ll ans = (ll)1e18;

    for (int i = 0; i <= 256; i++) {
        if (i * M * N > B) break;
        ll time = 0;
        for (int j = 0; j <= 256; j++) {
            if (j > i) {
                time += (j - i) * 2 * cnt[j];
            }
            if (j < i) {
                time += (i - j) * cnt[j];
            }
        }
        if (time <= ans) {
            ans = time;
            height = i;
        }
    }
    cout << ans << " " << height;
    return 0;
}

