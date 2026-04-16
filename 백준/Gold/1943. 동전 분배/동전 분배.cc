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
const int inf = 1e9;
//int dx[4] = { 1,-1,0,0 };
//int dy[4] = { 0,0,1,-1 };
//int dx[8] = { 1,1,1,-1,-1,-1,0,0 };
//int dy[8] = { 1,0,-1,1,0,-1,1,-1 };
//const double pi = 3.14159265358979323846;



int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int T = 3;
    while (T--) {
        vector<bool> DP(50001);
        DP[0] = 1;
        int N;
        cin >> N;
        int total = 0;
        for (int i = 0; i < N; i++) {
            int x;
            cin >> x;
            int n; 
            cin >> n;
            for (int j = min(50000,total); j >= 0; j--) {
                if (DP[j]) {
                    for (int k = 1; k <= n; k++) {
                        if (j + k * x > 50000) break;
                        DP[j + k * x] = true;
                    }
                }
            }
            total += x * n;
        }
        if (total % 2) cout << 0;
        else if (DP[total / 2]) cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;

}