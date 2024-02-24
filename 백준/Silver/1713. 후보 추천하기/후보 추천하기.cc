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

int rec[101];
int t[101]; 

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    rec[0] = inf;
    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;
        if (rec[x]) {
            rec[x] += 1;
        }
        else if (N != 0) {
            rec[x] = 1;
            t[x] = i;
            N -= 1;
        }
        else{
            int mnidx = 0;
            for (int j = 1; j <= 100; j++) {
                if (rec[j] == 0) continue;
                if (rec[j] == rec[mnidx] && t[j] < t[mnidx]) {
                    mnidx = j;
                }
                else if (rec[j] < rec[mnidx]) {
                    mnidx = j;
                }
            }
            rec[mnidx] = 0;
            rec[x] = 1;
            t[x] = i;
        }

    }
    for (int i = 1; i <= 100; i++) {
        if (rec[i]) cout << i << " ";
    }
    
    return 0;
}