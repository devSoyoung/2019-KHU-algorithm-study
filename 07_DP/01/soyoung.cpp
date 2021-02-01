#include <string>
#include <vector>

using namespace std;

int answer = -1;
void DFS(int N, int count, int currentNumber, int number) {
    if (count > 8) return;
    if (currentNumber == number) {
        // 현재 횟수가 지금까지보다 작거나 처음인 경우
        if (count < answer || answer == -1) {
            answer = count;
            return;
        }
    }
    
    int nn = 0;
    for (int i = 0; i < 8; i++) {
        // 5, 55, 555 등을 만들기 위한 연산
        nn = nn * 10 + N;
        DFS(N, count + 1 + i, currentNumber + nn, number);
        DFS(N, count + 1 + i, currentNumber - nn, number);
        DFS(N, count + 1 + i, currentNumber * nn, number);
        DFS(N, count + 1 + i, currentNumber / nn, number);
    }
}

int solution(int N, int number) {
    // 두 숫자가 일치하는 경우 한 번만 사용하는 것으로 출력
    if (N == number) {
        return 1;
    }
    DFS(N, 0, 0, number);
    return answer;
}