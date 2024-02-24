#include <iostream>
#include<cstring>
#include <vector> 
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<long long> distance;
    long long tmp;
    for(int i=0;i<N-1;i++){
        cin >> tmp;
        distance.push_back(tmp);
    }
    vector<long long> oilcost;
    for(int i=0; i<N;i++){
        cin >> tmp;
        oilcost.push_back(tmp);
    }
    long long min_cost;
    min_cost = oilcost[0];
    
    long long total = 0;
    
    for(int i=0; i<N-1;i++){
        if(oilcost[i]<min_cost){
            min_cost = oilcost[i];
        }
        total += min_cost * distance[i];
    }
    cout << total;
}