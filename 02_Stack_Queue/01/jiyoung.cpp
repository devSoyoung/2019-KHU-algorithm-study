#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int solution(vector<int> priorities, int location) {

	/*
		priorites를 정렬한 priority_queue를 두고 priorites element를 for문으로 탐색하면서 
		priority_queue의 마지막 element(가장 높은 중요도)와 같을 때 출력을하면서 priority_queue에서도 pop한다.
		priority_queue가 empty될 때 까지 반복
	*/

	int answer = 0;
	vector<int> priority_queue(priorities); 
	sort(priority_queue.begin(), priority_queue.end());

	while (!priority_queue.empty()) {
		for (int i = 0; i < priorities.size();i++) {
			if (priorities[i] == priority_queue.back()) { // 중요도가 가장 높을 때
				priority_queue.pop_back(); //출력
				answer++;
				if (i == location)
					return answer;
			}
		}
	}

		return answer;
}