// 문제는 풀었는데, 풀이 시간이 오래 걸려서
// 다른 방법을 고려해보는게 좋을 것 같아요.

#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <functional>
using namespace std;

bool isPossibleMake(string number, string maxNumber) {
    for (int i = 0; i < number.length(); i++) {
        bool isFind = false;
        for (int j = 0; j < maxNumber.length(); j++) {
            if (number[i] != maxNumber[j]) {
                continue;
            }
            
            // 같으면 maxNumber에서 해당 숫자 제거
            maxNumber.erase(j, 1);
            isFind = true;
            break;
        }
        
        if (!isFind) {
            return false;
        }
    }
    return true;
}

// 소수 판별: 제곱근 방식 이용
bool isPrimeNumber(int number) {
    const int sqrtNumber = (int)sqrt(number);
    for (int i = 2; i <= sqrtNumber; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

int solution(string numbers) {
    sort(numbers.begin(), numbers.end(), greater<int>());
    const int maxNumber = stoi(numbers);
    
    int answer = 0;
    for (int i = 2; i <= maxNumber; i++) {
        if (!isPossibleMake(to_string(i), to_string(maxNumber))) {
            continue;
        }
        
        if (isPrimeNumber(i)) {
            answer++;
        }
    }
    return answer;
}