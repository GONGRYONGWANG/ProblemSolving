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



ll U[200001];
ll Z[200001];
vector<int> E[200001];
vector<int> rE[200001];
int ind[200001];
bool visited[200001];

struct cmp{
    bool operator()(pll& a, pll& b){
        return a.second>b.second;
    }
};

void solve(int tc) {
    
    int N;
    cin>>N;
    
    for(int i=1; i<=N;i++){
        cin>>U[i]>>Z[i];
        int R; cin>>R;
        E[i].resize(R);
        for(int& nx: E[i]) {
            cin>>nx;
            rE[nx].push_back(i);
        }
        ind[i] = R;
    }
    
    pq<pll,vector<pll>, cmp> q;
    for(int i=1; i<=N;i++){
        q.push({i,Z[i]});
    }
    
    for(int i=1; i<=N;i++){
        bool b =false;
        for(int nx:E[i]){
            b |= (nx==i);
        }
        if(!b) continue;
        visited[i] = true;
        for(int& p:rE[i]){
            if(visited[p]) continue;
            ind[p] -=1;
            if(ind[p]==0){
                ll sum = U[p];
                for(int& nx: E[p]) sum += Z[p];
                Z[p]= min(Z[p],sum);
                q.push({p,Z[p]});
            }
        }
    }
    
    while(!q.empty()){
        int x = q.top().first;
        q.pop();
        if(visited[x]) continue;
        visited[x]=true;
        for(int& p: rE[x]){
            if(visited[p]) continue;
            ind[p] -=1;
            if(ind[p]==0){
                ll sum = U[p];
                for(int& nx: E[p]) sum += Z[nx];
                Z[p]= min(Z[p],sum);
                q.push({p,Z[p]});
            }
        }
    }
    
    cout<<Z[1];

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