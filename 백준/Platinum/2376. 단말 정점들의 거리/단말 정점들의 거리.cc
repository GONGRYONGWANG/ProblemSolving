// template: https://github.com/GONGRYONGWANG/ProblemSolving/blob/main/template.txt
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
#include<vector>
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
#define INF ll(9e18)
const int inf = 1e9 + 7;
const long double pi = 3.14159265358979323846;
const string debug = "output: ";
#define all(x) (x).begin(), (x).end()
#include<fstream>
ifstream fin; ofstream fout;

//int dx[4] = { -1,0,1,0 }; 
//int dy[4] = { 0,-1,0,1 }; 
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

struct treeNode
{
    treeNode() {};
    treeNode* l = nullptr, * r = nullptr;
    treeNode* p = nullptr;
    int depth = 0;
};

treeNode* node[1001];

void dfs(treeNode* cur) {
    if (cur->l) {
        cur->l->depth = cur->depth + 1;
        dfs(cur->l);
    }
    if (cur->r) {
        cur->r->depth = cur->depth + 1;
        dfs(cur->r);
    }
}

void solve(int tc) {


    int N;
    cin >> N;
    
    node[1] = new treeNode();
    node[1]->p = new treeNode();
    node[1]->p->l = node[1];

    for (int i = 1; i < N; i++) {
        int d;
        cin >> d;
        d -= 1;
        treeNode* cur = node[i]->p;
        while (1) {
            if (cur->r == nullptr) break;
            if (cur->p == nullptr) {
                cur->p = new treeNode();
                cur->p->l = cur;
            }
            cur = cur->p;
            d -= 1;
        }
        cur->r = new treeNode();
        cur->r->p = cur;
        cur = cur->r;
        d -= 1;
        while (d != 0) {
            cur->l = new treeNode();
            cur->l->p = cur;
            cur = cur->l;
            d -= 1;
        }
        node[i + 1] = cur;
    }

    treeNode *root = node[1];
    while (root->p) {
        root = root->p;
    }
    root->depth = 0;
    dfs(root);

    int u, v;
    cin >> u >> v;

    treeNode* a = node[u], * b = node[v];
    int ans = 0;
    while (a != b) {
        if (a->depth >= b->depth) {
            a = a->p;
            ans += 1;
        }
        else {
            b = b->p;
            ans += 1;
        }
    }
    cout << ans;


}
    



int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    //fin.open("input.txt"); fout.open("output.txt");
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}