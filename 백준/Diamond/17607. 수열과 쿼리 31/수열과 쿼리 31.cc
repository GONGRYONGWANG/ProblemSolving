//#pragma warning(disable:4996) 
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
#define INF (1<<32)
typedef unsigned int uint;
typedef pair<int, int> pii;

struct node {
    node* l; node* r; node* p;
    int cnt;
    int val;
    int ls, rs, mxs;
    bool rv;
    node() : l(nullptr), r(nullptr), p(nullptr) {}
    node(int v) {
        l = r = p = nullptr;
        cnt = 1;
        val = v;
        if (val == 1) {
            ls = rs = mxs = 1;
        }
        else {
            ls = rs = mxs = 0;
        }
        rv = 0;
    }
};

node* root;

void lazyProp(node* x) {
    if (!x->rv)  return;
    node* tmp = x->l;
    x->l = x->r;
    x->r = tmp;
    if (x->l) {
        x->l->rv = !x->l->rv;
        int tmpi = x->l->ls;
        x->l->ls = x->l->rs;
        x->l->rs = tmpi;
    }
    if (x->r) {
        x->r->rv = !x->r->rv;
        int tmpi = x->r->ls;
        x->r->ls = x->r->rs;
        x->r->rs = tmpi;
    }
    x->rv = 0;
    return;
}

void update(node* x) {
    lazyProp(x);
    x->cnt = 1;

    int mids=0;
    if (x->val == 1) {
        mids = 1;
    }

    if (x->l) {
        x->cnt += x->l->cnt;
        if (mids) mids += x->l->rs;
    }
    if (x->r) {
        x->cnt += x->r->cnt;
        if (mids) mids += x->r->ls;
    }

    if (x->l && x->l->cnt == x->l->mxs && mids) {
        x->ls = mids;
    }
    else if (x->l) x->ls = x->l->ls;
    else x->ls = mids;

    if (x->r && x->r->cnt == x->r->mxs && mids) {
        x->rs = mids;
    }
    else if (x->r) x->rs = x->r->rs;
    else x->rs = mids;

    x->mxs = mids;
    if (x->l) x->mxs = max(x->mxs, x->l->mxs); 
    if (x->r) x->mxs = max(x->mxs, x->r->mxs);
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
        if (x->p->l == p) {
            x->p->l = x;
        }
        else x->p->r = x;
    }
    else root = x;
    update(p);
    update(x);
    return;
}

void splay(node* x) {
    while (x->p) {
        node* p = x->p;
        node* g = p->p;
        if (g) {
            if ((g->l == p) == (p->l == x)) {
                rotate(p);
            }
            else rotate(x);
        }
        rotate(x);
    }
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
        if (k == 0) break;
        k -= 1;
        x = x->r;
        lazyProp(x);
    }
    splay(x);
    return;
}

void turn(int l, int r) {
    findKth(l - 1);
    node* x = root;
    root = x->r;
    root->p = nullptr;
    findKth(r - l + 1);
    x->r = root;
    root->p = x;
    root = x;
    x = x->r->l;
    x->rv = !x->rv;
    while (x) {
        update(x); x = x->p;
    }
    return;
}

int get(int l, int r) {
    findKth(l - 1);
    node* x = root;
    root = x->r;
    root->p = nullptr;
    findKth(r - l + 1);
    x->r = root;
    root->p = x;
    root = x;
    return x->r->l->mxs;
}


int N, M;
void init() {
    cin >> N;
    //dummy left
    node* x;
    root = x = new node(0);
    int A;
    for (int i = 0; i < N; i++) {
        cin >> A;
        x->p = new node(A);
        x->p->l = x;
        x = x->p;
        x->cnt = x->l->cnt + 1;
    }
    //dummy right
    root = x;
    x->r = new node(0);
    x->r->p = x;
    cin >> M;
    return;
}

void query() {
    int a, L, R;
    while (M--) {
        cin >> a >> L >> R;
        switch (a) {
        case 1:
            turn(L, R);
            break;
        case 2:
            cout<< get(L, R)<<endl;
            break;
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

    init();
    query();

    return 0;
}