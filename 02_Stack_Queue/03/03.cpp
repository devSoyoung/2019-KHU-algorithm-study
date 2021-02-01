/*
vector<int> sticks 선언
0. for 문으로 전체 탐색 시행 

1. 입력값이 '('이 인지 확인하기.
1)yes -> ')'인지 확인
(1)yes -> sticks에 1 추가하고, i++
(2)no -> sticks에 1을 push_back한다.


2)no -> sticks에서 pop_back 해서 해당 값을 answer에 추가
*/


#include <string>
#include <vector>
using namespace std;


int solution(string arrangement) {
	vector<int> sticks;
	int answer = 0;
	for (int i = 0; i < arrangement.size(); i++) {
		if (arrangement[i] == '(') {
			if (arrangement[i + 1] == ')') {
				for (int j = 0; j < sticks.size(); j++) {
						sticks[j]++;
				}
				i++;
			}
			else {
				sticks.push_back(1);
			}
		}
		else {
			answer += sticks[sticks.size()-1];
			sticks.pop_back();
		}
	}
	return answer;
}