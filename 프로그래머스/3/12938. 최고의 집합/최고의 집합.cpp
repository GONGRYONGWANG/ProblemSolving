#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    int N = n;
    
    if(s<N) return {-1};
    
    
    
    for(int i=s%N; i<N;i++) answer.push_back(s/N);
    for(int i=0; i<s%N;i++) answer.push_back(s/N+1);
    
    return answer;
}