// template: https://github.com/GONGRYONGWANG/ProblemSolving/blob/main/template.txt
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
#include<cctype>
#include<vector>
#include<array>
#include<utility>
#include<list>
#include<queue>
#include<stack>
#include<deque>
#include<tuple>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<cstdlib>
#include<ctime> // srand(time(0))
#include<regex> // 정규표현식
#include<random> // rand
#include<complex> // complex number
#include<numeric>
#include<cassert>
#include <climits>
#include <immintrin.h> // AVX, AVX2, AVX-512 // #pragma GCC optimize ("O3,unroll-loops") //#pragma GCC target ("avx,avx2,fma")
#include<chrono>
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
#define INF ll(2e18)
const int inf = 1000000007;
const long double pi = acosl(-1);
const string debug = "debug: ";
#define all(x) (x).begin(), (x).end()

#include<fstream>
ifstream fin; ofstream fout;

//#define cin fin 
//#define cout fout

//int dx[4] = { -1,0,1,0 };
//int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////

int tree[2000000];
void update(int node, int start, int end, int x, int v){
    if(x>end||x<start) return;
    if(start==end){
        tree[node] +=v;
        return;
    }
    int mid=(start+end)/2;
    update(node*2,start,mid,x,v);
    update(node*2+1,mid+1,end,x,v);
    tree[node] = tree[node*2]+tree[node*2+1];
}

int get(int node, int start, int end, int left,int right){
    if(left>end||right<start) return 0;
    if(left<=start && right>=end) return tree[node];
    int mid= (start+end)/2;
    return get(node*2,start,mid,left,right)+get(node*2+1,mid+1,end,left,right);
}

ll arr[500001];

ll mod = 998244353;


void solve(int tc) {

    
    int N,Q;
    cin>>N>>Q;
    
    
    vector<ll> init(N);
    for(int i=1; i<=N;i++) {
        cin>>arr[i];
        update(1,1,N,arr[i],1);
        init[i-1] = arr[i]; 
    }
    sort(init.begin(),init.end());
    
    ll ret= 0;
    for(int i=0; i<N;i++){
        ll x = init[i];
        ret += x*(x-1)/2*(N-1-i);
        ret%=mod;
    }
    
    while(Q--){
        int v,x;
        cin>>v>>x;
        update(1,1,N,arr[v],-1);
        if(x==1){
            ret += arr[v] * get(1,1,N,arr[v]+1,N);
            arr[v]+=1;
            update(1,1,N,arr[v],1);
        }
        else{
            ret -= (arr[v]-1)*get(1,1,N,arr[v],N);
            arr[v]-=1;
            update(1,1,N,arr[v],1);
        }
        ret = (ret%mod+mod)%mod;
        cout<<ret<<endl;
    }



    // cout << "Case #" << tc << ": " << ret<< endl;
}

int main() {
    //fin.open("input.txt"); fout.open("output.txt");
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}