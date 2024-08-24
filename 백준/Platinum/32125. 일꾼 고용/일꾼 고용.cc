// template: https://github.com/GONGRYONGWANG/ProblemSolving/blob/main/template.txt
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
typedef long long ll;
using namespace std;
using namespace __gnu_cxx;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;



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




void solve() {

    unordered_map<int,ordered_multiset> m;

    int N, K;
    cin >> N >> K;
    vector <bool> type(N+1);
    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        type[i] = (x == 1);
    }

    ll ans = 0;

    int cnt=0;
    ll work=0;
    m[cnt].insert(work);
    for(int i=1; i<=N;i++){

        if(type[i]) cnt+=1;
        else cnt-=1;

        ll x;
        cin>>x;

        if(type[i]) work+=x;
        else work-=x;

        if(!m[cnt].empty()){
            ans += ll(m[cnt].order_of_key(work+K+1)-m[cnt].order_of_key(work-K));
        }
        m[cnt].insert(work);
    }

    cout<<ans<<endl;







}



int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
