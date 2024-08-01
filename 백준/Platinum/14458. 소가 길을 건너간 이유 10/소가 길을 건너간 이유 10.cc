#include<bits/stdc++.h>
#include<ext/rope>
/*
string s;
s.c_str() -> 스트링을 char arr로
rope<char> rp(s.c_str());
rp.insert(idx, s.c_str());
rp.insert(idx, some_char);'
cout<<rp.substr(idx, length);
*/

using namespace std;
using namespace __gnu_cxx;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;


typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef unsigned int uint;

#define pq priority_queue
#define endl "\n"

const ll INF = 1e18;
const int inf = 1e9;
const double pi = 3.14159265358979323846;

const string debug = "output: ";

ll gcd(ll a, ll b) {
    if (a < b) swap(a, b);
    while (b != 0) {
        ll  n = a % b;
        a = b;
        b = n;
    }
    return a;
}

ll lcm(ll a, ll b) {
    ll g = gcd(a, b);
    return a / g * b;
}

ll powmod(ll x, ll n, ll mod) {
    if (n == 0) return 1;
    if (n % 2) return x * powmod(x, n - 1, mod) % mod;
    ll half = powmod(x, n / 2, mod);
    return half * half % mod;
}

ll modinv(ll x, ll mod) {
    return powmod(x, mod - 2, mod);
}

ll factorial(ll x) {
    ll ret = 1;
    // ret = F[x];
    return ret;
}

ll combination(ll n, ll r, ll mod) {
    return factorial(n) * modinv(factorial(n - r), mod) % mod * modinv(factorial(r), mod) % mod;
}

//int dx[4] = { 1,-1,0,0 };
//int dy[4] = { 0,0,1,-1 };
//int dx[8] = { -1,-1,-1,0,0,1,1,1 };
//int dy[8] = { -1,0,1,-1,1,-1,0,1 };


///////////////////////////////////////////////


int A[100000];
int B[100000];
int Aidx[100001];
int Bidx[100001];
pll Ainv[100000];
pll Binv[100000];
ordered_set os;

void solve() {
    ll N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        Aidx[A[i]] = i;
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
        Bidx[B[i]] = i;
    }



    Ainv[0].first = 0;
    os.insert(Bidx[A[0]]);
    for(int i=1; i<N;i++){
        int x = Bidx[A[i]];
        Ainv[i].first = Ainv[i-1].first + ll(os.size() - os.order_of_key(x));
        os.insert(x);
    }

    os.clear();
    Ainv[N-1].second = 0;
    os.insert(Bidx[A[N-1]]);
    for(int i=N-2; i>=0; i--){
        int x = Bidx[A[i]];
        Ainv[i].second = Ainv[i+1].second + ll(os.order_of_key(x));
        os.insert(x);
    }

    os.clear();
    Binv[0].first =0;
    os.insert(Aidx[B[0]]);
    for(int i=1; i<N;i++){
        int x = Aidx[B[i]];
        Binv[i].first = Binv[i-1].first + ll(os.size()- os.order_of_key(x));
        os.insert(x);
    }

    os.clear();
    Binv[N-1].second = 0;
    os.insert(Aidx[B[N-1]]);
    for(int i=N-2; i>=0; i--){
        int x = Aidx[B[i]];
        Binv[i].second = Binv[i+1].second + ll(os.order_of_key(x));
        os.insert(x);
    }

    ll ans = Ainv[0].second;

    for(ll i=0; i<N-1; i++){
        ans = min(ans , 2*Ainv[i].first+2*Ainv[i+1].second+(i+1)*(N-i-1)-Ainv[0].second);
        ans = min(ans , 2*Binv[i].first+2*Binv[i+1].second+(i+1)*(N-i-1)-Binv[0].second);
    }
    cout<<ans;

}



int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
