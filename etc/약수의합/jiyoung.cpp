#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
	int i, answer = 0;
	for (i = 1; i*i < n; i++) { // �����ٱ��� ..
		if (n%i == 0) { // ������ ��������
			answer += i;
			answer += n / i;
		}
	}
	if (i*i == n) // �������̸� 
		answer += i;
	return answer;
}