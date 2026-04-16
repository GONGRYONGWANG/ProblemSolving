//#pragma warning(disable:4996) 
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define inf 1e9

vector<char> v;
vector<char> out;
int L, C;

int vow, con;

bool isvow(char x) {
    if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
        return 1;
    }
    return 0;
}

void get(int idx, int k) {
    if (C - idx < k) return;
    if (k == 0) {
        if (vow < 1 || con < 2) return;
        for (int i = 0; i < out.size(); i++) {
            cout << out[i];
        }
        cout << endl;
        return;
    }
    out.push_back(v[idx]);
    if (isvow(out.back())) {
        vow += 1;
    }
    else con += 1;
    get(idx + 1, k - 1);
    if (isvow(out.back())) {
        vow -= 1;
    }
    else con -= 1;
    out.pop_back();
    get(idx + 1, k);
    return;
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> L >> C;
    v.resize(C);
    for (int i = 0; i < C; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    vow = con = 0;
    get(0, L);

    return 0;
}