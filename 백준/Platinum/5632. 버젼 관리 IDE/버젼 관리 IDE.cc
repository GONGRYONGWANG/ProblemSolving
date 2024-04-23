#include<bits/stdc++.h>
#include<ext/rope>
using namespace std;
using namespace __gnu_cxx;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

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

rope<char> r[50001];
void solve(){

    r[0] = "";
    int T;
    cin>>T;
    int d=0;
    int ver = 0;
    while(T--){
        int a,v,p,c;
        string s;
        cin>>a;
        if(a==1){
            cin>>p>>s;
            p-=d;
            ver+=1;
            r[ver] = r[ver-1];
            r[ver].insert(p,s.c_str());
        }
        else if(a==2){
            cin>>p>>c;
            p-=d;
            c-=d;
            ver+=1;
            r[ver]=r[ver-1];
            r[ver].erase(p-1,c);
        }
        else{
            cin>>v>>p>>c;
            v-=d; p-=d; c-=d;
            rope<char> tmp = r[v].substr(p-1,c);
            for(auto iter = tmp.begin(); iter!= tmp.end();iter++){
                cout<<*iter;
                if(*iter=='c') d+=1;
            }
            cout<<endl;

        }

    }





}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
