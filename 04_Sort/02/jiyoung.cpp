#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool compare(int _a, int _b) { // 각 문자열 합한 것끼리 비교
	int i = 0;
	string a_b = to_string(_a) + to_string(_b);
	string b_a = to_string(_b) + to_string(_a);

	return (stoi(a_b) > stoi(b_a));
}

string solution(vector<int> numbers) {
	string answer = "";
	sort(numbers.begin(), numbers.end(), compare);
	for (int i = 0; i < numbers.size(); i++)
		answer += to_string(numbers[i]);
	if (answer == string(answer.length(), '0')) //0000...-> 0
		answer = "0";
	return answer;
}

int main() {
	vector<int> numbers = { 3,30,34,5,9 };
	solution(numbers);
	
	system("pause");
	return 0;
}