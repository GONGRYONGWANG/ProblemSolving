#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
const int inf = 1e9 + 7;
#define endl "\n"



void solve(int tc) {

	int N;
	cin >> N;

    ll total =0;
    vector<ll> arr(N);
    for(int i=0; i<N;i++){
        ll a,b;
        cin>>a>>b;
        total += a;
        arr[i]= b-a;
    }

    sort(arr.begin(),arr.end());

    vector<ll> psum(N);
    psum[0] =arr[0];

    for(int i=1; i<N;i++){
        psum[i] = psum[i-1]+arr[i];
    }



    ll x = 0;

    int Q;
    cin>>Q;

    while(Q--){

        char c;
        cin>>c;
        ll val;
        cin>>val;

        if(c=='A'){
            total += val*N;
            x+=val;
        }
        else{
            x-=val;
        }

        auto it = upper_bound(arr.begin(),arr.end(),x);

        if(it==arr.end()){
            cout<<total<<endl;
            continue;
        }

        if(it==arr.begin()){
            cout<<total + psum[N-1] - x*N<<endl;
            continue;
        }

        int idx = it-arr.begin();
        cout<< total + psum[N-1] - psum[idx-1] - x*(N-idx)<<endl;

    }





}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T = 1;
	//cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		solve(tc);
	}
	return 0;
}
