#include<bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
const int inf = 1e9+7;

vector<int> solution(int target) {
    vector<int> answer;
    vector<pii> arr(target+1,{inf,inf});
    arr[0] = {0,0};
    for(int i=1; i<=target;i++){
        for(int d = 1; d<=60 && i-d>=0; d++){
            pii ret = arr[i-d];
            
            if(d<=20) ret.first+=1;
            else if(d==50) ret.first+=1;
            else if((d%2==0&&d/2<=20) || d%3==0) ret.second+=1;
            else continue;
            
            if(ret.first+ret.second<arr[i].first+arr[i].second) arr[i] = ret;
            else if(ret.first+ret.second == arr[i].first+arr[i].second && ret.first>arr[i].first) arr[i]=ret;
        }
    }
    
    answer = {arr[target].first+arr[target].second , arr[target].first};
    
    return answer;
}