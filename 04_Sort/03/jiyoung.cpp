#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

/*
	citations 배열을 내림차순으로 정렬했을때, 요소의 값이 index와 같거나 그보다 작아질 때 그 index가 h-index가 되는 것을 확인할 수 있음.
*/

int solution(vector<int> citations) {
	int answer = 0;
	int index = 0;

	sort(citations.begin(), citations.end(), greater<int>());

	while (index < citations.size())
	{
		if (citations[index] <= index)
			break;

		index++;
	}

	answer = index;
	return answer;
}



int main() {
	vector<int> v = { 1,7,0,1,6,4 };
	cout << solution(v) << endl;
	system("pause");
	return 0;
}