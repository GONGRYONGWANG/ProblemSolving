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
#include<ctime> 
#include<random> // rand
#include<complex> // complex
#include<numeric>
#include<regex>
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
const double pi = 3.14159265358979323846;



ll arr[250000];

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N, K;
    cin >> N >> K;
    set<ll> s;
    for (int i = 0; i < K; i++) {
        ll x;
        cin >> x;
        x = x * 250000 + i;
        arr[i] = x;
        s.insert(x);
    }

    ll ans = 0;
    auto median = s.begin();

    for (int i = 0; i < (K - 1) / 2 ; i++) {
        median++;
    }
    ans+=*median / 250000;

    for (int i = K; i < N; i++) {
        ll x;
        cin >> x;
        x = x * 250000 + i;
        arr[i] = x;
        ll y = arr[i - K];
        if (y == *median) {
            if (x > *median) {
                s.insert(x);
                median++;
                s.erase(y);
            }
            else {
                s.insert(x);
                median--;
                s.erase(y);
            }
        }
        else if ((y < *median) == (x < *median)) {
            s.erase(y);
            s.insert(x);
        }
        else {
            if (y < *median) {
                s.insert(x);
                s.erase(y);
                median++;
            }
            else {
                s.insert(x);
                s.erase(y);
                median--;
            }
        }
        ans += *median / 250000;
    }
    cout << ans;

    
    return 0;
}