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

#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")
#include <bits/stdc++.h>
#include <x86intrin.h>

int lazy[712];
int arr[500544];

void update(int l, int r , int x){
    if(x==0) return;

    __m256i xor_value = _mm256_set1_epi32(x);

    int i = l;

    while (i < r && (i % 8) != 0) {
        arr[i] ^= x;
        i++;
    }

    for(; i+8<=r; i+=8){
        __m256i data = _mm256_loadu_si256((__m256i*)&arr[i]);
        __m256i result = _mm256_xor_si256(data, xor_value);
        _mm256_storeu_si256((__m256i*)&arr[i], result);
    }
    for(; i<=r;i++){
        arr[i]^=x;
    }
}


void lazyProp(int bck){
    int x = lazy[bck];
    lazy[bck]=0;
    if(x==0) return;
    update(bck*704, (bck+1)*704-1,x);
}


void updatebck(int lbck, int rbck , int x){
    if(x==0) return;

    __m256i xor_value = _mm256_set1_epi32(x);

    int i= lbck;

    while(i<rbck && (i%8)!=0){
        lazy[i] ^=x;
        i++;
    }

    for(; i+8<=rbck;i+=8){
        __m256i data = _mm256_loadu_si256((__m256i*)&lazy[i]);
        __m256i result = _mm256_xor_si256(data, xor_value);
        _mm256_storeu_si256((__m256i*)&lazy[i], result);
    }
    for(; i<=rbck;i++){
        lazy[i]^=x;
    }
}


void solve() {

    int N;
    cin>>N;
    for(int i=0; i<N;i++) cin>>arr[i];
    int Q;
    cin>>Q;
    while(Q--){
        int t;
        cin>>t;
        if(t==1){
            int l,r,x;
            cin>>l>>r>>x;
            int lbck = l/704; int rbck = r/704;
            lazyProp(lbck); lazyProp(rbck);
            if(lbck ==rbck){
                update(l,r,x);
                continue;
            }
            update(l,(lbck+1)*704-1,x);
            updatebck(lbck+1 , rbck-1 , x);
            update(rbck*704,r,x);
        }
        else{
            int idx;
            cin>>idx;
            lazyProp(idx/704);
            cout<<arr[idx]<<endl;
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
