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


int arr[1000000];
void solve() {
    int x;
    cin >> x;
    if (cin.eof()) return;
    x *= 10000000;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    int l = 0;
    int r = N - 1;
    while (l < r) {
        if (arr[l] + arr[r] == x) {
            cout << "yes " << arr[l] << " " << arr[r] << endl;
            return;
        }
        else if (arr[l] + arr[r] < x) {
            l += 1;
        }
        else {
            r -= 1;
        }
    }
    cout << "danger" << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while (!cin.eof()) {
        solve();
    }
    return 0;
}