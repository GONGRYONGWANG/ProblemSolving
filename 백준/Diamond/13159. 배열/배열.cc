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
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<ctime> 
#include<random> // rand
#include<complex> // complex
#include<numeric>
#include<regex>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef complex<double> cpx;
#define pq priority_queue
#define endl "\n"
//int dx[4] = { 1,-1,0,0 };
//int dy[4] = { 0,0,1,-1 };
//int dx[8] = { 1,1,1,-1,-1,-1,0,0 };
//int dy[8] = { 1,0,-1,1,0,-1,1,-1 };
const double pi = 3.14159265358979323846;


struct node {
    node* l, * r, * p;
    int sz;
    int val;
    ll mn, mx, sum;
    bool rv;
    node(int v) {
        l = r = p = nullptr;
        sz = 1;
        val = mn = mx = sum = v;
        rv = 0;
    }
};

node* root;
node* ptr[300001];

void lazyProp(node* x) {
    if (!x->rv) return;
    swap(x->l, x->r);
    if (x->l) x->l->rv = !x->l->rv;
    if (x->r) x->r->rv = !x->r->rv;
    x->rv = 0;
    return;
}

void update(node* x) {
    x->sz = 1;
    x->sum = x->mn = x->mx = x->val;
    if (x->l) {
        x->sz += x->l->sz;
        x->mn = min(x->mn, x->l->mn);
        x->mx = max(x->mx, x->l->mx);
        x->sum += x->l->sum;
    }
    if (x->r) {
        x->sz += x->r->sz;
        x->mn = min(x->mn, x->r->mn);
        x->mx = max(x->mx, x->r->mx);
        x->sum += x->r->sum;
    }
    return;
}

void rotate(node* x) {
    node* p = x->p;
    node* b = nullptr;
    if (p->l == x) {
        p->l = b = x->r;
        x->r = p;
    }
    else {
        p->r = b = x->l;
        x->l = p;
    }
    x->p = p->p;
    p->p = x;
    if (b) b->p = p;
    if (x->p) {
        if (x->p->l == p) x->p->l = x;
        else x->p->r = x;
    }
    else root = x;
    update(p); update(x);
    return;
}

void splay(node* x) {
    while (x->p) {
        node* p = x->p;
        node* g = p->p;
        if (g) {
            if ((g->l == p) == (p->l == x)) rotate(p);
            else rotate(x);
        }
        rotate(x);
    }
    return;
}

void findKth(int k) {
    node* x = root;
    lazyProp(x);
    while (1) {
        while (x->l && x->l->sz > k) {
            x = x->l;
            lazyProp(x);
        }
        if (x->l) k -= x->l->sz;
        if (k == 0) break;
        k -= 1;
        x = x->r;
        lazyProp(x);
    }
    splay(x);
    return;
}

void gather(int L, int R) {
    findKth(L - 1);
    node* x = root;
    root = x->r;
    root->p = nullptr;
    findKth(R - L + 1);
    root->p = x;
    x->r = root;
    root = x;
    return;
}

int N, M;

void turn(int L, int R) {
    if (L == R) return;
    gather(L, R);
    node* x = root->r->l;
    x->rv = !x->rv;
}

ll mn_, mx_, sum_;
void get(int L, int R) {
    gather(L, R);
    node* x = root->r->l;
    mn_ = x->mn;
    mx_ = x->mx;
    sum_ = x->sum;
}

void init() {
    cin >> N >> M;
    node* cur;
    root = cur = new node(0); // left dummy
    for (int i = 1; i <= N; ++i) {
        ptr[i] = cur->r = new node(i);
        cur->r->p = cur;
        cur = cur->r;
    }
    cur->r = new node(0); // right dummy
    cur->r->p = cur;
    cur = cur->r;
    while (cur) {
        update(cur); cur = cur->p;
    }
}

void query() {
    for (int i = 0; i < M; i++) {
        int q, l, r, x;
        cin >> q;
        if (q == 1) {
            cin >> l >> r;
            get(l, r);
            cout << mn_ << " " << mx_ << " " << sum_ << endl;
            turn(l, r);
        }
        else if (q == 2) {
            cin >> l >> r >> x;
            get(l, r);
            cout << mn_ << " " << mx_ << " " << sum_ << endl;
            if (x < 0) {
                x = -x;
                x %= (r - l + 1);
                if (x != 0) {
                    turn(l, r);
                    turn(l, r - x);
                    turn(r - x + 1, r);
                }
            }
            else if (x > 0) {
                x %= (r - l + 1);
                if (x != 0) {
                    turn(l, r);
                    turn(l, l + x - 1);
                    turn(l + x, r);
                }
            }
        }
        else if (q == 3) {
            cin >> x;
            findKth(x);
            cout << root->val << endl;
        }
        else {
            cin >> x;
            stack<node*> st;
            node* cur = ptr[x];
            while (cur) {
                st.push(cur);
                cur = cur->p;
            }
            while (!st.empty()) {
                lazyProp(st.top());
                st.pop();
            }
            splay(ptr[x]);
            cout << root->l->sz << endl;
        }
    }
}

void showTree(node* x) {
    if (!x) return;
    lazyProp(x);
    showTree(x->l);
    if (x->val) cout << x->val << " ";
    showTree(x->r);
    return;
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    init();
    query();
    showTree(root);
    return 0;
}