#include <string>
#include <vector>

using namespace std;

int d[1000000];

int getnx(int x, int dir){
    if(dir==0) return x+d[x];
    else if(dir==1) return x+1;
    else return x-d[x];
}


vector<int> solution(int n) {
    vector<int> answer;
    answer.resize(n*(n+1)/2);
    
    int x = 0;
    for(int i=1; i<=n;i++){
        for(int j= x; j<x+i;j++){
            d[j] = i;
        }
        x+=i;
    }
    
    
    x = 0;
    int dir = 0;
    for(int i=1; i<=n*(n+1)/2; i++){
        answer[x] = i;
        int nx = getnx(x,dir);
        if(nx >=n*(n+1)/2 || (dir==1 && d[x]!=d[nx]) || answer[nx]){
            dir = (dir+1)%3;
            nx = getnx(x,dir);
        }
        x = nx;
    }
    return answer;
}