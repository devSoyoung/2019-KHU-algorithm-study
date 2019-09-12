#include <string>
#include <vector>
using namespace std;

#define studentsNum 3

vector<int> solution(vector<int> answers) {
    vector<int> answer;

	int** mathfailers = new int*[studentsNum];
	int length1[studentsNum] = { 5, 8, 10 };
	mathfailers[0] = new int[length1[0]]{ 1, 2, 3, 4, 5 };
	mathfailers[1] = new int[length1[1]]{ 2, 1, 2, 3, 2, 4, 2, 5 };
	mathfailers[2] = new int[length1[2]]{ 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

	int score[3] = { 0, };
	int length2 = answers.size();
	for (int i = 0; i < studentsNum; i++) {
		for (int j = 0; j < length2; j++) {
			if (mathfailers[i][j % length1[i]] == answers[j])
				score[i]++;
		}
	}

	int max = score[0];
	for (int i = 0; i < studentsNum; i++) {
		if (score[i] > max)
			max = score[i];
	}

	for (int i = 0; i < studentsNum; i++) {
		if (score[i] == max)
			answer.push_back(i + 1);
	}

	return answer;
}
