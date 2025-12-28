#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef complex<double> cpx;
typedef long double ld;
#define pq priority_queue
#define endl "\n"
#define INF ll(4e18)
const int inf = 1e9 + 7;
const long double pi = 3.14159265358979323846;
const string debug = "output: ";


//int dx[4] = { -1,0,1,0 }; 
//int dy[4] = { 0,-1,0,1 }; 
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////


int arr[100001];
bool isnprime[1000001];
void solve(int tc) {

    if (tc == 1) {
        isnprime[1] = true;
        for (ll i = 2; i <= 1000000; i++) {
            if (isnprime[i]) continue;
            for (ll j = i * i; j <= 1000000; j += i) {
                isnprime[j] = true;
            }
        }
        arr[1] = 1;
        for (int i = 2; i <= 100000; i++) {
            int x = i;
            int d = 10;
            bool flag = true;
            if (isnprime[x + 1]) flag = false;
            while (d <= x) {
                if (isnprime[(x / d) * (x % d) + 1]) flag = false;
                d *= 10;
            }
            arr[i] = arr[i - 1] + flag;
        }
    }

    int N;
    cin >> N;
    cout << arr[N] << endl;




}




int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}