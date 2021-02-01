#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int solution(vector<int> priorities, int location) {

	/*
		priorites�� ������ priority_queue�� �ΰ� priorites element�� for������ Ž���ϸ鼭 
		priority_queue�� ������ element(���� ���� �߿䵵)�� ���� �� ������ϸ鼭 priority_queue������ pop�Ѵ�.
		priority_queue�� empty�� �� ���� �ݺ�
	*/

	int answer = 0;
	vector<int> priority_queue(priorities); 
	sort(priority_queue.begin(), priority_queue.end());

	while (!priority_queue.empty()) {
		for (int i = 0; i < priorities.size();i++) {
			if (priorities[i] == priority_queue.back()) { // �߿䵵�� ���� ���� ��
				priority_queue.pop_back(); //���
				answer++;
				if (i == location)
					return answer;
			}
		}
	}

		return answer;
}