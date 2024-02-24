//#pragma warning(disable:4996) 
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
#define INF (1<<32)
typedef unsigned int uint;

struct node {
    node* l; node* r; node* p;
    int cnt;
    uint val;
    uint sum[11];
    node() : l(nullptr), r(nullptr), p(nullptr) {}
    node(uint v) {
        l = r = p = nullptr;
        val = v;
        cnt = 1;
        for (int i = 0; i <= 10; i++) sum[i] = val;
    }
};

node* root;

int comb[11][11];

void saveComb() {
    comb[0][0] = 1;
    for (int i = 1; i <= 10; i++) {
        comb[i][0] = 1; comb[i][i] = 1;
        for (int j = 1; j < i; j++) {
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
        }
    }
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
    uint t = 0;
    if (x->l) {
        t = x->l->cnt;
    }
    uint cf[11];
    cf[0] = 1;
    for (int i = 1; i <= 10; i++) cf[i] = cf[i - 1] * (t + 1);
    for (int i = 0; i <= 10; i++) x->sum[i] = cf[i] * x->val;
    for (int i = 0; i <= 10; i++) {
        if (x->l) x->sum[i] += x->l->sum[i];
        if (x->r) {
            for (int j = 0; j <= i; j++) {
                x->sum[i] += cf[i - j] * comb[i][j] * x->r->sum[j];
            }
        }
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
        if (x->p->l == p) {
            x->p->l = x;
        }
        else x->p->r = x;
    }
    else {
        root = x;
    }
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

void findKth(int k) { // starting from 1st; 0th=dummy
    node* x = root;
    while (1) {
        while (x->l && x->l->cnt > k) {
            x = x->l;
        }
        if (x->l) k -= x->l->cnt;
        if (k==0) break;
        k -= 1;
        x = x->r;
    }
    splay(x);
    return;
}


void changeVal(int k, ll c) {
    findKth(k);
    root->val = c;
    return;
}



void append(int p, ll v) {
    findKth(p);
    node* x = root->p = new node;
    x->r = root;
    root->p = x;
    x->l = root->l;
    root->l = nullptr;
    x->l->p = x;
    x->p = nullptr;
    x->val = v;
    update(root);
    update(x);
    root = x;
    return;
}

void del(int p) {
    findKth(p);
    node* x = root;
    root = x->l;
    root->p = nullptr;
    findKth(p - 1);
    root->r = x->r;
    x->r->p = root;
    update(root);
    return;
}




unsigned int get(int l,int r, int k) {
    findKth(l - 1);
    node* x = root;
    root = x->r;
    root->p = nullptr;
    findKth(r - l + 1);
    x->r = root;
    root->p = x;
    root = x;
    return x->r->l->sum[k];
}

int N, M;
void init() {
    saveComb();
    cin >> N;
    //dummy left
    node* x;
    root = x = new node;
    x->l = x->r = x->p = nullptr;
    x->cnt = 1;
    x->val = 0;
    //

    ll A;
    for (int i = 0; i < N; i++) {
        cin >> A;
        x->p = new node;
        x->p->l = x;
        x = x->p;
        x->r = x->p = nullptr;
        x->cnt = x->l->cnt + 1;
        x->val = A;
    }
    root = x;
    //dummy right
    x->r = new node;
    x->r->p = x;
    x = x->r;
    x->l = x->r = nullptr;
    x->cnt = 1;
    x->val = 0;
    //
    cin >> M;
    return;
}

void query() {
    ll a, p, v, l, r, k;
    for (int i = 0; i < M; i++) {
        cin >> a;
        switch (a) {
        case 1:
            cin >> p >> v;
            append(p+1, v);
            break;
        case 2:
            cin >> p;
            del(p + 1);
            break;
        case 3:
            cin >> p >> v;
            changeVal(p+1, v);
            break;
        case 4:
            cin >> l >> r >> k;
            cout << get(l + 1, r + 1, k)<<endl;
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