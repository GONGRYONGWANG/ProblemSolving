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

int gcd(int a, int b) {
    if (a < b) swap(a, b);
    while (b != 0) {
        int x = a % b;
        a = b;
        b = x;
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    int M = arr[1]-arr[0];
    for (int i = 2; i < N; i++) {
        M = gcd(M, arr[i] - arr[i - 1]);
    }
    
    vector<int> ans = {M};
    for (int i = 2; i <= sqrt(M); i++) {
        if (M % i == 0) {
            ans.push_back(i);
            if (i * i != M) ans.push_back(M / i);
        }
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }

    return 0;
}