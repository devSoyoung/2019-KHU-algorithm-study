#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
	int i, answer = 0;
	for (i = 1; i*i < n; i++) { // 제곱근까지 ..
		if (n%i == 0) { // 나누어 떨어지면
			answer += i;
			answer += n / i;
		}
	}
	if (i*i == n) // 제곱근이면 
		answer += i;
	return answer;
}