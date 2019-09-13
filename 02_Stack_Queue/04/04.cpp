/*

vector<int> ���� �ö� �ִ� Ʈ���� ���� = in_bridge_weight
int ���� �ö� �ִ� Ʈ���� ������ ���� = sum_in_bridge_weight
vector<int> �ö� Ʈ���� ���� ��Ȳ = in_bridge_time

int �ð� ���� = answer

0. ��� Ʈ���� �ְų� ���� ���� Ʈ���� ���� ������ �ݺ��մϴ�.

1. Ʈ���� �����Ȳvector�� �Ǿ��� ���� �ٸ��� ���̶� ���ٸ� �����Ȳ vector���� ����ϴ�. �ƴ϶�� ��� +1

2. ��ƿ �� �ִ� ���� >= ���� �ö��ִ� Ʈ���� ������ ���� + �ø� Ʈ���� ����
Ʈ���� �ϳ� �߰��մϴ�.(���Ʈ������ �����մϴ�. + ����ö��ִ� Ʈ���� ���Կ� ���մϴ�.+ �ö� Ʈ���� ���� ��Ȳ�� push_back)

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
