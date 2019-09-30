#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 0;
    vector<int> movingTime(truck_weights.size(),0); //이동 시간
    int on_weights=0;
    int in = 0; int out= -1; // 들어간 트럭의 index, 나간 트럭의 index
    
    while(in < truck_weights.size()){
        
        if(on_weights+truck_weights[in]<=weight){
            movingTime[in]=bridge_length;
            on_weights+=truck_weights[in];
            in++;
            if(in==truck_weights.size()){
                time+=bridge_length+1;
                return time;
            }
        }
        
        //시간 경과
        for(int i=out+1;i<in;i++)
            movingTime[i]--; // 이동시간 감소
        time++;
        //다리 지남
        if(movingTime[out+1]==0){
            on_weights-=truck_weights[++out];
        }
    }
        
    return time;
}