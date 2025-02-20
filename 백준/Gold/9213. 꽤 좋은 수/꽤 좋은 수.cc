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

int arr[1000000];
vector<int> v[1000];

void solve(int tc) {

    for (int i = 1; i < 1000000; i++) {
        for (int j = i * 2; j < 1000000; j += i) {
            arr[j] += i;
        }
        if(abs(arr[i]-i)<1000) v[abs(arr[i]-i)].push_back(i);
    }

    vector<vector<int>> query;
    for (int t = 1;; t++) {
        int s, e, b;
        cin >> s >> e >> b;
        if(s==0) break;
        query.push_back({ b,s,e,t });
    }

    sort(query.begin(), query.end());

    vector<int> ans(query.size()+1);

    ordered_set os;

    int idx= -1;
    for(int i=0; i<query.size();i++){
        int s,e,b,t;
        b = query[i][0]; s = query[i][1]; e = query[i][2]; t = query[i][3];
        while(idx!=b){
            idx+=1;
            for(int x:v[idx]) os.insert(x);
        }
        ans[t] = os.order_of_key(e+1) - os.order_of_key(s);
    }

    for(int i=1; i<ans.size();i++){
        cout<<"Test "<<i<<": "<<ans[i]<<endl;
    }



}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    //fin.open("input.txt"); fout.open("output.txt");
    //fin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}
