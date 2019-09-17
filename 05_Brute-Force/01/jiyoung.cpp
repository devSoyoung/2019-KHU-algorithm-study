#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


vector<int> solution(vector<int> answers) {
	vector<int> score(3);
	vector<int> result;
	int arr0[5] = { 1,2,3,4,5 };
	int arr1[8] = { 2,1,2,3,2,4,2,5 };
	int arr2[10] = { 3,3,1,1,2,2,4,4,5,5 };

	for (int i = 0; i < answers.size(); i++) {
		if (answers[i] == arr0[i % 5])
			score[0]++;
		if (answers[i] == arr1[i % 8])
			score[1]++;
		if (answers[i] == arr2[i % 10])
			score[2]++;
	}
	int max = *max_element(score.begin(), score.end());

	for (int i = 0; i < 3; i++)
	{
		if (score[i] == max)
			result.push_back(i + 1);
	}

	return result;
}