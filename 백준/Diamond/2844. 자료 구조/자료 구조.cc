//구현 2. mmap/write 이용
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////
/*
 * Author : jinhan814
 * Date : 2021-05-06
 * Source : https://blog.naver.com/jinhan814/222266396476
 * Description : FastIO implementation for cin, cout. (mmap ver.)
 */
constexpr int SZ = 1 << 20;

class INPUT {
private:
    char* p;
    bool __END_FLAG__, __GETLINE_FLAG__;
public:
    explicit operator bool() { return !__END_FLAG__; }
    INPUT() {
        struct stat st; fstat(0, &st);
        p = (char*)mmap(0, st.st_size, PROT_READ, MAP_SHARED, 0, 0);
    }
    bool IsBlank(char c) { return c == ' ' || c == '\n'; }
    bool IsEnd(char c) { return c == '\0'; }
    char _ReadChar() { return *p++; }
    char ReadChar() {
        char ret = _ReadChar();
        for (; IsBlank(ret); ret = _ReadChar());
        return ret;
    }
    template<typename T> T ReadInt() {
        T ret = 0; char cur = _ReadChar(); bool flag = 0;
        for (; IsBlank(cur); cur = _ReadChar());
        if (cur == '-') flag = 1, cur = _ReadChar();
        for (; !IsBlank(cur) && !IsEnd(cur); cur = _ReadChar()) ret = 10 * ret + (cur & 15);
        if (IsEnd(cur)) __END_FLAG__ = 1;
        return flag ? -ret : ret;
    }
    string ReadString() {
        string ret; char cur = _ReadChar();
        for (; IsBlank(cur); cur = _ReadChar());
        for (; !IsBlank(cur) && !IsEnd(cur); cur = _ReadChar()) ret.push_back(cur);
        if (IsEnd(cur)) __END_FLAG__ = 1;
        return ret;
    }
    double ReadDouble() {
        string ret = ReadString();
        return stod(ret);
    }
    string getline() {
        string ret; char cur = _ReadChar();
        for (; cur != '\n' && !IsEnd(cur); cur = _ReadChar()) ret.push_back(cur);
        if (__GETLINE_FLAG__) __END_FLAG__ = 1;
        if (IsEnd(cur)) __GETLINE_FLAG__ = 1;
        return ret;
    }
    friend INPUT& getline(INPUT& in, string& s) { s = in.getline(); return in; }
} _in;

class OUTPUT {
private:
    char write_buf[SZ];
    int write_idx;
public:
    ~OUTPUT() { Flush(); }
    explicit operator bool() { return 1; }
    void Flush() {
        write(1, write_buf, write_idx);
        write_idx = 0;
    }
    void WriteChar(char c) {
        if (write_idx == SZ) Flush();
        write_buf[write_idx++] = c;
    }
    template<typename T> int GetSize(T n) {
        int ret = 1;
        for (n = n >= 0 ? n : -n; n >= 10; n /= 10) ret++;
        return ret;
    }
    template<typename T> void WriteInt(T n) {
        int sz = GetSize(n);
        if (write_idx + sz >= SZ) Flush();
        if (n < 0) write_buf[write_idx++] = '-', n = -n;
        for (int i = sz; i --> 0; n /= 10) write_buf[write_idx + i] = n % 10 | 48;
        write_idx += sz;
    }
    void WriteString(string s) { for (auto& c : s) WriteChar(c); }
    void WriteDouble(double d) { WriteString(to_string(d)); }
} _out;

/* operators */
INPUT& operator>> (INPUT& in, char& i) { i = in.ReadChar(); return in; }
INPUT& operator>> (INPUT& in, string& i) { i = in.ReadString(); return in; }
template<typename T, typename std::enable_if_t<is_arithmetic_v<T>>* = nullptr>
INPUT& operator>> (INPUT& in, T& i) {
    if constexpr (is_floating_point_v<T>) i = in.ReadDouble();
    else if constexpr (is_integral_v<T>) i = in.ReadInt<T>(); return in; }

OUTPUT& operator<< (OUTPUT& out, char i) { out.WriteChar(i); return out; }
OUTPUT& operator<< (OUTPUT& out, string i) { out.WriteString(i); return out; }
template<typename T, typename std::enable_if_t<is_arithmetic_v<T>>* = nullptr>
OUTPUT& operator<< (OUTPUT& out, T i) {
    if constexpr (is_floating_point_v<T>) out.WriteDouble(i);
    else if constexpr (is_integral_v<T>) out.WriteInt<T>(i); return out; }

/* macros */
#define fastio 1
#define cin _in
#define cout _out
#define istream INPUT
#define ostream OUTPUT
/////////////////////////////////////////////////////////////////////////////////////////////
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
#include<ctime> // srand(time(0))
#include<regex> // 정규표현식
#include<random> // rand
#include<complex> // complex
#include<numeric>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef complex<double> cpx;
#define pq priority_queue
#define endl "\n"
#define inf 1e9
//int dx[4] = { 1,-1,0,0 };
//int dy[4] = { 0,0,1,-1 };
//int dx[8] = { 1,1,1,-1,-1,-1,0,0 };
//int dy[8] = { 1,0,-1,1,0,-1,1,-1 };
const double pi = 3.14159265358979323846;


struct node {
    node* l, * r, * p;
    ll sz;
    ll val, sum;
    ll a, d;
    ll b;
    node(int v) {
        l = r = p = nullptr;
        sz = 1;
        val = sum = v;
        a = d = 0;
        b = -1;
    }
};

node* root;

void lazyProp(node* x) {
    if (x->b != -1) {
        x->val = x->b;
        if (x->l) {
            x->l->b = x->b;
            x->l->a = x->l->d = 0;
            x->l->sum = x->l->sz * x->b;
        }
        if (x->r) {
            x->r->b = x->b;
            x->r->a = x->r->d = 0;
            x->r->sum = x->r->sz * x->b;
        }
    }
    x->val += x->a;
    if (x->l) {
        x->l->a += x->a;
        x->l->d += x->d;
        x->l->sum += x->l->sz * x->a + x->l->sz * (x->l->sz - 1) * x->d / 2;
        x->val += x->d * x->l->sz;
    }
    if (x->r) {
        x->r->a += x->a + (x->sz - x->r->sz) * x->d;
        x->r->d += x->d;
        x->r->sum += x->r->sz * (x->a + (x->sz - x->r->sz) * x->d) + x->r->sz * (x->r->sz - 1) * x->d / 2;
    }
    x->b = -1; x->a = x->d = 0;
    return;
}

void update(node* x) {
    x->sz = 1;
    x->sum = x->val;
    if (x->l) {
        x->sz += x->l->sz;
        x->sum += x->l->sum;
    }
    if (x->r) {
        x->sz += x->r->sz;
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


void init() {
    cin >> N >> M;
    node* cur;
    root = cur = new node(0); // left dummy
    for (int i = 1; i <= N; i++) {
        ll x;
        cin >> x;
        cur->r = new node(x);
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
        int q, l, r, c;
        ll x;
        cin >> q;
        if (q == 1) {
            cin >> l >> r >> x;
            gather(l, r);
            node* cur = root->r->l;
            cur->a = cur->d = 0;
            cur->b = x;
            cur->sum = cur->sz * x;
            update(root->r);
            update(root);
        }
        else if (q == 2) {
            cin >> l >> r >> x;
            gather(l, r);
            node* cur = root->r->l;
            cur->a += x;
            cur->d += x;
            cur->sum += (cur->sz + 1) * x * cur->sz / 2;
            update(root->r);
            update(root);
        }
        else if (q == 3) {
            cin >> c >> x;
            findKth(c);
            node* cur = root->l;
            cur->p = new node(x);
            cur->p->l = cur;
            cur = cur->p;
            cur->p = root;
            root->l = cur;
            update(cur);
            update(root);
        }
        else {
            cin >> l >> r;
            gather(l, r);
            cout << root->r->l->sum << endl;
        }
    }
}


int main() {
    init();
    query();
    return 0;
}