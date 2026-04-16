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
const double pi = 3.14159265358979323846;


int arr[1001];
vector<int> E[1001];


int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    vector<pii> v;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        E[b].push_back(a);
    }
    
    for (int i = 1; i <= N; i++) {
        if (E[i].size() == 0) {
            arr[i] = 1;
        }
        else {
            for (int j = 0; j < E[i].size(); j++) {
                arr[i] = max(arr[i], arr[E[i][j]] + 1);
            }
        }
        cout << arr[i] << " ";
    }

    return 0;
}