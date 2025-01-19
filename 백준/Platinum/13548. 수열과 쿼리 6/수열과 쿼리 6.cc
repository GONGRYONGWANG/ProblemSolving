#include<iostream>
#include<vector>
#include<algorithm>     
#include<cmath>

using namespace std;

int SQRTN;
int max_freq = 0;

int freq[101010];
int freq_cnt[101010];
vector <int> vec;
int ans[101010];

struct Query{
    int idx,left,right;
    bool operator < (const Query &x){
        if(left/SQRTN!=x.left/SQRTN) return left/SQRTN < x.left/SQRTN;
        return right<x.right;
    }
};


void add(int x){
    if(freq[x]) freq_cnt[freq[x]]--;
    freq[x]++;
    freq_cnt[freq[x]]++;
    max_freq = max(max_freq,freq[x]);
}

void remove(int x){
    freq_cnt[freq[x]]--;
    if(max_freq == freq[x]&&!freq_cnt[freq[x]]) max_freq--;
        freq[x]--;
        freq_cnt[freq[x]]++;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;

    SQRTN = sqrt(n);    
    vec.resize(n+1);
    for(int i = 1;i<=n;i++){
        cin>>vec[i];
    }
    int m;
    cin>>m;
    vector <Query> q;
    for(int i = 0;i<m;i++){
        int a,b;
        cin>>a>>b;
        q.push_back({i,a,b});
    }
    
    sort(q.begin(),q.end());

    int l = q[0].left, r = q[0].right;
    max_freq = 0;
    for(int i = l;i<=r;i++){
        if(freq_cnt[freq[vec[i]]]) freq_cnt[freq[vec[i]]]--;
        freq[vec[i]]++;
        freq_cnt[freq[vec[i]]]++;
        max_freq = max(max_freq,freq[vec[i]]);
    }
    ans[q[0].idx] = max_freq;

    for(int i = 1;i<m;i++){
        while(l>q[i].left) add(vec[--l]);
        while(r<q[i].right) add(vec[++r]);
        while(l<q[i].left) remove(vec[l++]);
        while(r>q[i].right) remove(vec[r--]);
        ans[q[i].idx] = max_freq;
    }

    for(int i = 0;i<m;i++){
        cout<<ans[i]<<'\n';
    }

    return 0;
}