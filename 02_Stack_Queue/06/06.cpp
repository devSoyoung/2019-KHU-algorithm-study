/*

�ڽź��� ����
������ �迭�� ������� �ʴ´ٴ� ���� �������. �ƿ����ٰ� �����ϴ� ���� �������ϴ�.

*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


vector<int> solution(vector<int> prices) {
	vector<int> answer;
	int cnt;
	for (int i = 0; i < prices.size() - 1; i++) {
		cnt = 1;
		for (int j = i + 1; j < prices.size() - 1; j++) {
			if (prices[i] > prices[j])
				break;
			cnt++;
		}
		answer.push_back(cnt);
	}
	answer.push_back(0);
	return answer;
}