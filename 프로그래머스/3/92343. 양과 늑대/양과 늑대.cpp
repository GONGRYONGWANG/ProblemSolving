#include <string>
#include <vector>

using namespace std;

bool visited[(1<<17)];

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 1;
    int N = info.size();
    for(int i=0; i<(1<<N);i++) visited[i] = false;
    visited[1] = true;
    
    for(int i=0;i<(1<<N);i++){
        int a=0; int b=0;
        for(int j=0; j<N;j++){
            if(i&(1<<j)){
                if(!info[j]) a+=1;
                else b+=1;
            }
        }
        if(b>=a) visited[i]= false;
        if(!visited[i]) continue;
        answer = max(answer,a);
        for(int k=0;k<N-1;k++){
            int u = edges[k][0]; int v = edges[k][1];
            if(!(i&(1<<u))) swap(u,v);
            if(!(i&(1<<u))) continue;
            if(i&(1<<v)) continue;
            visited[i|(1<<v)] = true;
        }
    }
    
    
    return answer;
}