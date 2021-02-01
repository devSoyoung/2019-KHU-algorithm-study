/*

자신부터 세고
마지막 배열은 고려하지 않는다는 것을 고려하자. 아예없다고 생각하는 것이 마음편하다.

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