#include <string>
#include <string.h>
#include <vector>
using namespace std;
#define MAX 1000001

bool IsPrime[MAX];

int solution(int n) {
	int answer = 0;
	memset(&IsPrime, true, sizeof(bool) * MAX); // IsPrime true로 초기화
	IsPrime[1] = false;

	for (int i = 2; i <= n; i++) {
		if (IsPrime[i]) { // 소수일 때 
			answer++;
			for (int j = 2; i*j <= n; j++)
				IsPrime[i*j] = false; // 그 배수는 소수가 아님
		}
	}
	return answer;
}