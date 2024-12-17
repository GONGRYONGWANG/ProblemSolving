// template: https://github.com/GONGRYONGWANG/ProblemSolving/blob/main/gcctemplate_for_pbds&rope
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

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef unsigned int uint;


typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;

# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2") //SIMD



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

ifstream fin; ofstream fout;
//int dx[4] = { 0,1,0,-1 };
//int dy[4] = { 1,0,-1,0 };
//int dx[8] = { -1,-1,-1,0,0,1,1,1 };
//int dy[8] = { -1,0,1,-1,1,-1,0,1 };

string deb = "debug: ";

struct PiiHasher { // unordered_set<pii, PiiHasher>
    size_t operator()(const pii& x) const {
        return hash<long long>()(((long long)x.first) ^ (((long long)x.second) << 32));
    }
};



void solve() {

    int Q;
    cin>>Q;
    unordered_map<ll, unordered_set<ll>> m;
    ordered_multiset os1, os2;
    while(Q--){
        int t;
        cin>>t;
        if(t==1){
            ll x;
            cin>>x;
            cout<<os1.order_of_key(x*x)-os2.order_of_key(x*x+1)<<endl;

        }
        else{
            ll x,y;
            cin>>x>>y;
            if(!m[x].count(y)){
                m[x].insert(y);
                os1.insert(x*x);
                os2.insert(x*x+y*y);
            }
            else{
                m[x].erase(y);
                os1.erase(os1.find_by_order(os1.order_of_key(x*x)));
                os2.erase(os2.find_by_order(os2.order_of_key(x*x+y*y)));
            }
        }
    }





}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    //fin.open("input.txt"); fout.open("output.txt");
    //fin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
