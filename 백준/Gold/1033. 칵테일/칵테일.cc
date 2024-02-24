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


vector<int> E[10];
vector<int> Edge[10];
int arr[10];

int gcd(int a, int b) {
    if (a < b) swap(a, b);


    while (b != 0) {
        int n = a % b;
        a = b;
        b = n;
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N;
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b, p, q;
        cin >> a >> b >> p >> q;
        E[a].push_back(b);
        E[b].push_back(a);
        Edge[i] = { a,b,p,q };
    }

    for (int i = 0; i < N; i++) {
        arr[i] = 1;
    }

    for (int i = 0; i < N - 1; i++) {
        int a, b, p, q;
        a = Edge[i][0];
        b = Edge[i][1];
        p = Edge[i][2];
        q = Edge[i][3];
        vector<bool> visited(N, false);
        visited[a] = visited[b] = true;

        queue<int> Q;
        Q.push(a);
        while (!Q.empty()) {
            int node = Q.front();
            Q.pop();
            arr[node] *= p;
            for (int i = 0; i < E[node].size(); i++) {
                int nxt = E[node][i];
                if (visited[nxt]) continue;
                visited[nxt] = true;
                Q.push(nxt);
            }
        }
        Q.push(b);
        while (!Q.empty()) {
            int node = Q.front();
            Q.pop();
            arr[node] *= q;
            for (int i = 0; i < E[node].size(); i++) {
                int nxt = E[node][i];
                if (visited[nxt]) continue;
                visited[nxt] = true;
                Q.push(nxt);
            }
        }
    }




    int GCD = arr[0];
    for (int i = 1; i < N; i++) {
        GCD = gcd(GCD, arr[i]);
    }
    for (int i = 0; i < N; i++) {
        cout << arr[i] / GCD << " ";
    }
    return 0;
}