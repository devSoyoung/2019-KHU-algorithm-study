#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    queue<int> bridge;
    for(int i = 0; i < bridge_length; i++)
        bridge.push(0);

    int total_weight = 0;
    while(!bridge.empty()) {
        if(bridge.front() != 0)
            total_weight -= bridge.front();

        bridge.pop();

        if(truck_weights.size() != 0) {
            if(total_weight + truck_weights[0] <= weight) {
                total_weight += truck_weights[0];
                bridge.push(truck_weights[0]);
                truck_weights.erase(truck_weights.begin());
            } else
                bridge.push(0);
        }

        answer++;
    }

    return answer;
}
