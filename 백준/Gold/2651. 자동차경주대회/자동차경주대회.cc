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



vector<int> arr[102]; // time,dist,idx
int parent[102];
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int D;
    cin >> D;
    int N;
    cin >> N;
    arr[0] = { 0,0,0 };
    for (int i = 1; i <= N + 1; i++) {
        arr[i].resize(3,0);
        cin >> arr[i][1];
        arr[i][1] += arr[i - 1][1];
    }
    for (int i = 1; i <= N; i++) {
        cin >> arr[i][0];
        arr[i][2] = i;
    }
    pq<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
    q.push({ 0,0,0 });
    for (int i = 1; i <= N + 1; i++) {
        while (q.top()[1] + D < arr[i][1]) q.pop();
        arr[i][0] += q.top()[0];
        parent[i] = q.top()[2];
        q.push(arr[i]);
    }

    cout << arr[N + 1][0] << endl;

    stack<int> ans;
    int x = parent[N + 1];
    while (x) {
        ans.push(x);
        x = parent[x];
    }
    cout << ans.size() << endl;
    while (!ans.empty()) {
        cout << ans.top() << " ";
        ans.pop();
    }
    return 0;
}