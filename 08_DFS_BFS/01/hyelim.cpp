#include <string>
#include <vector>
#include <cmath>
#include <string.h>
using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;

	int vlen = numbers.size();
	int rlen = pow(2, vlen);
	int* result = new int[rlen];
	memset(result, 0, sizeof(int) * rlen);
	for (int i = 0; i < vlen; i++) {
		for (int j = 0; j < rlen; j++) {
			if ((j / (int)(rlen / pow(2, i + 1))) % 2 == 0)
				result[j] += numbers[i];
			else
				result[j] -= numbers[i];
		}
	}

	for (int i = 0; i < rlen; i++) {
		if (result[i] == target)
			answer++;
	}

	return answer;
}
