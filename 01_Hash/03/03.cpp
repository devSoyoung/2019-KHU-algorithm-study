#include <string>
#include <vector>
#include <iostream>
using namespace std;

/*
순열 조합 문제

안낀다는 선택지도 추가해서

(각 장비의 선택지의 곱) - 1

장비의 종류별로 나누기 갯수만 세면됨

vector<int> 갯수
vector<string> 이름

*/


int solution(vector<vector<string>> clothes) {
	int answer = 1;
	vector<int> item_num;
	vector<string> item_name;
	bool is_new;
	while (!clothes.empty()) {
		is_new = true;
		for (int i =0; i < item_name.size(); i++) {
			if (clothes[0][1] == item_name[i]) {
				is_new = false;
				item_num[i]++;
				break;
			}
		}
		if (is_new) {
			item_name.push_back(clothes[0][1]);
			item_num.push_back(1);
		}
		clothes.erase(clothes.begin());
	}
	for (int i = 0; i < item_num.size(); i++) {
		answer *= item_num[i] + 1;
	}
	return answer - 1;
}

void main() {


	vector<vector<string>> clothes = { {"yellow","hat"}, {"blue","glasses"}, {"green","hat"} };

	cout << solution(clothes);
}