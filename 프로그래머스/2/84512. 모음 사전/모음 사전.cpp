#include <string>
#include <vector>

using namespace std;

int solution(string word) {
    int answer = 0;
    
    string s = "AEIOU";
    
    int cnt = 0;
    string v = "";
    for(int a=0; a<5;a++){
        v+=s[a];
        cnt += 1;
        if(v==word) return cnt;
        for(int b=0;b<5;b++){
            v+=s[b];
            cnt += 1;
            if(v==word) return cnt;
            for(int c=0;c<5;c++){
                v+=s[c];
                cnt += 1;
                if(v==word) return cnt; 
                for(int d=0;d<5;d++){
                    v+=s[d];
                    cnt += 1;
                    if(v==word) return cnt;
                    for(int e=0;e<5;e++){
                        v+=s[e];
                        cnt += 1;
                        if(v==word) return cnt;
                        v.pop_back();
                    }
                    v.pop_back();
                }
                v.pop_back();
            }
            v.pop_back();
        }
        v.pop_back();
    }
    
    
    
    return answer;
}