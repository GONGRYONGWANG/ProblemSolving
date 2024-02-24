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


bool visited[100001];

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N, K;
    cin >> N >> K;
    deque<pii> q;
    q.push_back({ 0,N });
    while (!q.empty()) {
        int t = q.front().first;
        int node = q.front().second;
        q.pop_front();
        if (visited[node]) continue;
        visited[node] = true;
        if (node == K) {
            cout << t;
            return 0;
        }
        if (node * 2 <= 100000 && !visited[node * 2]) q.push_front({ t, 2 * node });
        if (node - 1 >= 0 && !visited[node - 1]) q.push_back({ t + 1,node - 1 });
        if (node + 1 <= 100000 && !visited[node + 1]) q.push_back({ t + 1,node + 1 });
    }
    return 0;

}