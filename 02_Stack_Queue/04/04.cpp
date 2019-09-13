/*

vector<int> 현재 올라가 있는 트럭의 무게 = in_bridge_weight
int 현재 올라가 있는 트럭의 무게의 총합 = sum_in_bridge_weight
vector<int> 올라간 트럭의 진행 상황 = in_bridge_time

int 시간 측정 = answer

0. 대기 트럭이 있거나 진행 중인 트럭이 있을 때까지 반복합니다.

1. 트럭의 진행상황vector의 맨앞의 값이 다리의 길이랑 같다면 진행상황 vector에서 지웁니다. 아니라면 모두 +1

2. 버틸 수 있는 하중 >= 현재 올라가있는 트럭의 무게의 총합 + 올릴 트럭의 무게
트럭을 하나 추가합니다.(대기트럭에서 삭제합니다. + 현재올라가있는 트럭의 무게에 더합니다.+ 올라간 트럭의 진행 상황에 push_back)

3. answer++;

*/

#include <string>
#include <vector>

using namespace std;


int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	vector<int> in_bridge_weight;
	int sum_in_bridge_weight = 0;
	vector<int> in_bridge_time;
	
	while (!in_bridge_time.empty() || !truck_weights.empty()) {
		if (!in_bridge_time.empty()) {
			if (in_bridge_time[0] == bridge_length) {
				in_bridge_time.erase(in_bridge_time.begin());
				sum_in_bridge_weight -= in_bridge_weight[0];
				in_bridge_weight.erase(in_bridge_weight.begin());
			}
			for (int i = 0; i < in_bridge_time.size(); i++) {
				in_bridge_time[i]++;
			}
		}
		if (!truck_weights.empty()) {
			if (weight >= sum_in_bridge_weight + truck_weights[0]) {
				in_bridge_weight.push_back(truck_weights[0]);
				in_bridge_time.push_back(1);
				sum_in_bridge_weight += truck_weights[0];
				truck_weights.erase(truck_weights.begin());
			}
		}
		answer++;
	}
	return answer;
}
