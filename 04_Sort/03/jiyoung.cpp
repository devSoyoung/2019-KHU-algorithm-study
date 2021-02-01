#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

/*
	citations �迭�� ������������ ����������, ����� ���� index�� ���ų� �׺��� �۾��� �� �� index�� h-index�� �Ǵ� ���� Ȯ���� �� ����.
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