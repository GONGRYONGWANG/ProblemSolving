//#pragma warning(disable:4996) 
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define INF (1<<32)
typedef long long ll;
typedef unsigned int uint;
typedef pair<int, int> pii;
#define fi first
#define se second

struct node {
    node* l, * r, * p;
    int cnt;
    int val;
    bool rv;
    node(int v) {
        l = r = p = nullptr;
        cnt = 1;
        val = v;
        rv = 0;
    }
};

node* root;

void lazyProp(node* x) {
    if (!x->rv) return;
    swap(x->l, x->r);
    if (x->l) x->l->rv = !x->l->rv;
    if (x->r) x->r->rv = !x->r->rv;
    x->rv = 0;
    return;
}

void update(node* x) {
    x->cnt = 1;
    if (x->l) {
        x->cnt += x->l->cnt;
    }
    if (x->r) {
        x->cnt += x->r->cnt;
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
        while (x->l && x->l->cnt > k) {
            x = x->l;
            lazyProp(x);
        }
        if (x->l) k -= x->l->cnt;
        if (k==0) break;
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
    gather(L, R);
    node* x = root->r->l;
    x->rv = !x->rv;
}

void lift(int l, int r) {
    if (l == 1) return;
    turn(1, l - 1);
    turn(l, r);
    turn(1, r);
    return;
}

void drop(int l, int r) {
    if (r == N) return;
    turn(l, r);
    turn(r + 1, N);
    turn(l, N);
    return;
}

vector<int> seq, rip;

void saveSeq(node* x) {
    if (!x) return;
    lazyProp(x);
    saveSeq(x->l);
    seq.push_back(x->val);
    saveSeq(x->r);
    return;
}

void pushRip(node* x) {
    if (!x)return;
    lazyProp(x);
    pushRip(x->l);
    x->val = rip.back();
    rip.pop_back();
    pushRip(x->r);
    return;
}

void ripple(int L, int R) {
    gather(L, R);
    node* x = root->r->l;
    seq.clear();
    saveSeq(x);
    rip.resize(x->cnt);
    int mid = (x->cnt + 1) / 2;
    for (int i = 0; i < mid; i++) {
        rip[i * 2] = seq[i];
    }
    for (int i = mid; i < x->cnt; i++) {
        rip[(i - mid) * 2 + 1] = seq[i];
    }
    reverse(rip.begin(), rip.end());
    pushRip(x);
    return;
}

void init() {
    cin >> N >> M;
    node* x;
    root = x = new node(0);
    for (int i = 1; i <= N; ++i) {
        x->r = new node(i);
        x->r->p = x;
        x = x->r;
    }
    x->r = new node(0);
    x->r->p = x;
    x = x->r;
    while (x) {
        update(x); x = x->p;
    }
    return;
}

void query() {
    for (int i = 0; i < M; i++) {
        int a, x, y;
        cin >> a;
        switch (a) {
        case 1: 
            cin >> x >> y;
            lift(x, y);
            break;

        case 2: 
            cin >> x >> y;
            drop(x, y);
            break;
        case 3:
            cin >> x >> y;
            ripple(x, y);
            break;
        }
    }
    return;
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