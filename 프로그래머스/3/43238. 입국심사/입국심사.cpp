#include <string>
#include <vector>
using namespace std;

using ll = long long;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    ll l = 1; ll r = ll(times.front())*n;
    
    while(l<r){
        ll m = (l+r)/2;
        ll cnt =0 ;
        for(ll t : times){
            cnt += m/t;
        }
        if(cnt < n) l = m+1;
        else r = m;
    }
    
    answer = l;
    
    return answer;
}