/*
0. �迭�� ���Ұ� �ִ��� �ľ�.

1. �� ���� 100���� ũ�ų� ������ �ľ�

2-1. �ƴ϶�� ��� �迭�� speed��ŭ �߰��ϰ� 1�� �̵�

2-2. 100�̶�� ���� �͵� 100���� ũ�ų� ������ �ľ�

2-2-1. 100�̶�� 2-2�� ���ư�.

2-2-2. 100�� �ƴ϶�� 100�̿��� ��Ҹ� ī��Ʈ�ϴ� ���� answer�� �߰��ϰ�, �������� �迭���� �����Ѵ�. �� �� 1��
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

