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

string debug = "ans: ";

ll gcd(ll a, ll b) {
    if (a < b) swap(a, b);
    while (b != 0) {
        ll  n = a % b;
        a = b;
        b = n;
    }
    return a;
}


int dist(pii a, pii b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

//////////////////////////////////////////////////////////////////////////////////////



int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);  




    int N;
    cin >> N;
    vector<int> v;
    vector<int> idx;
    vector<int> arr;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
        auto it = lower_bound(v.begin(), v.end(), x);
        idx.push_back(it - v.begin());
        if (it == v.end()) {
            v.push_back(x);
        }
        else {
            *it = x;
        }
    }
    cout << v.size() << endl;
    stack<int> ans;
    int pos = v.size() - 1;
    for (int i = N - 1; i >= 0; i--) {
        if (idx[i] == pos) {
            pos -= 1;
            ans.push(arr[i]);
        }
    }
    while (!ans.empty()) {
        cout << ans.top() << " ";
        ans.pop();
    }

    return 0;
}