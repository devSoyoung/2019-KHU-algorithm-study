/*
vector<int> sticks ����
0. for ������ ��ü Ž�� ���� 

1. �Է°��� '('�� ���� Ȯ���ϱ�.
1)yes -> ')'���� Ȯ��
(1)yes -> sticks�� 1 �߰��ϰ�, i++
(2)no -> sticks�� 1�� push_back�Ѵ�.


2)no -> sticks���� pop_back �ؼ� �ش� ���� answer�� �߰�
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