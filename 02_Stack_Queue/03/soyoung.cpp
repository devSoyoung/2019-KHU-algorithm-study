#include <string>
#include <vector>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    int current_sticks = 0;
    for (int i = 0; i < arrangement.size(); i++) {
        if (arrangement[i] == '(') {
            // () 일 때: 레이저
            if (arrangement[i + 1] == ')') {
                answer += current_sticks;
                i++;        // 다음칸 지나가기
                continue;
            }
            
            current_sticks++;
        } else if (arrangement[i] == ')') {
            answer++;
            current_sticks--;
        }
    }
    return answer;
}
