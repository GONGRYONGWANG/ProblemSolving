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

int arr[200001];
vector<int> E[200001];
int ret =0;
int parent[200001];
set<int> st[200001];
int delta[200001];


void dfs(int x){
    
    if(E[x].size()==1 && x!=1){
        if(arr[x]==1) st[x].insert(1);
        delta[x] = 0;
        return;
    }
    for(int nx:E[x]){
        if(nx==parent[x]) continue;
        parent[nx] = x;
        dfs(nx);
        if(st[nx].size()> st[x].size()) {
            swap(st[nx],st[x]);
            swap(delta[nx],delta[x]);
        }
        while(!st[nx].empty()){
            st[x].insert(*st[nx].begin() + delta[nx] - delta[x]);
            st[nx].erase(st[nx].begin());
        }
    }
    
    
    delta[x] += arr[x];
    
    while(!st[x].empty() && *st[x].begin() + delta[x] < 0) {
        st[x].erase(st[x].begin());
    }
    
    if(!st[x].empty() && *st[x].begin() + delta[x] == 0 ) ret += 1;
    
}

void solve(int tc) {

    int N;
    cin>>N;
    for(int i=1; i<=N;i++){ 
        cin>>arr[i];
        if(arr[i]==0) arr[i] = -1;
    }
    
    for(int i=0; i<N-1;i++){
        int u,v;
        cin>>u>>v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    
    dfs(1);
    
    cout<<ret;




    // cout << "Case #" << tc << ": " << ret << endl;
}


int main() {
    // fin.open("input.txt"); fout.open("output.txt");
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}