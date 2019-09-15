#include <string>
#include <string.h>
#include <vector>
using namespace std;
#define MAX 1000001

bool IsPrime[MAX];

int solution(int n) {
	int answer = 0;
	memset(&IsPrime, true, sizeof(bool) * MAX); // IsPrime true�� �ʱ�ȭ
	IsPrime[1] = false;

	for (int i = 2; i <= n; i++) {
		if (IsPrime[i]) { // �Ҽ��� �� 
			answer++;
			for (int j = 2; i*j <= n; j++)
				IsPrime[i*j] = false; // �� ����� �Ҽ��� �ƴ�
		}
	}
	return answer;
}