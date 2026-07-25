#include <string>
#include <vector>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    vector<bool> ret(1000001,false);
    int N = elements.size();
    for(int i=1; i<N;i++){
        elements[i]+=elements[i-1];
        
    }
    
    for(int i=0; i<N;i++){
        ret[elements[i]] = true;
        for(int j=0; j<i;j++){
            ret[elements[i]-elements[j]] = true;
            ret[ elements[N-1]- elements[i] + elements[j]] = true;
        }
    }
    
    for(int i=1; i<=1000000;i++) answer+=ret[i];
    
    
    return answer;
}