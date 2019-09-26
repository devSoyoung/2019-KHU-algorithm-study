/*
0. 배열의 원소가 있는지 파악.

1. 맨 앞이 100보다 크거나 같은지 파악

2-1. 아니라면 모든 배열에 speed만큼 추가하고 1로 이동

2-2. 100이라면 다음 것도 100보다 크거나 같은지 파악

2-2-1. 100이라면 2-2로 돌아감.

2-2-2. 100이 아니라면 100이였던 요소를 카운트하던 값을 answer에 추가하고, 나머지는 배열에서 삭제한다. 그 후 1로
*/
#include <string>
#include <vector>
using namespace std;


vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	int cnt = 0;

	while (!progresses.empty()) {
		for (int i = 0; i < progresses.size(); i++) {
			progresses[i] += speeds[i];
		}

		if (progresses[0] >= 100) {
			while (!progresses.empty() && progresses[0] >= 100) {
				cnt++;
				progresses.erase(progresses.begin());
				speeds.erase(speeds.begin());
			}
			answer.push_back(cnt);
			cnt = 0;
		}
	}
	return answer;
}

