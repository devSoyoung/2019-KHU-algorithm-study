#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;

	for (int i = 0; i < commands.size(); i++) {
		vector<int> sub_array(array.begin() + (commands[i][0] - 1), array.begin() + commands[i][1]); // 부분 벡터 (commands[i][0]번째 ~ commands[i][1]번째)
		sort(sub_array.begin(), sub_array.end()); // 정렬
		answer.push_back(sub_array[commands[i][2] - 1]); // commands[i][2]번째 element
	}

	return answer;
}