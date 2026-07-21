#include<bits/stdc++.h>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    int N = truck_weights.size();
    vector<int> v(N);
    v[0] = 1;
    
    int f = 0;
    int total = truck_weights[0];
    for(int i=1; i<N;i++){
        total += truck_weights[i];
        while(total > weight){
            v[i] = v[f]+bridge_length;
            total -= truck_weights[f];
            f+=1;
        }
        v[i] = max(v[i] , v[i-1]+1);
    }
    
    answer = v.back()+bridge_length;
    
    return answer;
}