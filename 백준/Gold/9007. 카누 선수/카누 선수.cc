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
#include<complex> // complex number
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
//int dx[4] = { 1,-1,0,0 };
//int dy[4] = { 0,0,1,-1 };
//int dx[8] = { 1,1,1,-1,-1,-1,0,0 };
//int dy[8] = { 1,0,-1,1,0,-1,1,-1 };
const ll INF = 1e18;
const int inf = 1e9;
const double pi = 3.14159265358979323846;


int arr[4][1000];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int K, N;
        cin >> K >> N;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < N; j++) {
                cin >> arr[i][j];
            }
        }

        vector<int> l,r;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                l.push_back(arr[0][i] + arr[1][j]);
                r.push_back(arr[2][i] + arr[3][j]);
            }
        }
        r.push_back(-inf);
        r.push_back(inf);
        sort(r.begin(), r.end());

        int ans = inf;
        for (int i = 0; i < l.size(); i++) {
            auto iter = lower_bound(r.begin(), r.end(), K - l[i]);
            int ret = l[i] + *iter;
            if (abs(K - ret) == abs(ans - K) && ret < ans) {
                ans = ret;
            }
            else if (abs(K - ret) < abs(ans - K)){
                ans = ret;
            }
            iter--;
            ret = l[i] + *iter;
            if (abs(K - ret) == abs(ans - K) && ret < ans) {
                ans = ret;
            }
            else if (abs(K - ret) < abs(ans - K)) {
                ans = ret;
            }
        }

        cout << ans << endl;
    }



    return 0;
}