#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> answers) {
    int count[3] = { 0, };
    
    const int SECOND_ANSWER[4] = { 1, 3, 4, 5 };
    const int THIRD_ANSWER[5] = { 3, 1, 2, 4, 5 };
    
    vector<int>::iterator iter;
    int index = 0;
    for (iter = answers.begin(); iter != answers.end(); ++iter) {
        // 1번 학생
        if (*iter == (index % 5) + 1) {
            count[0] += 1;
        }
        
        // 2번 학생: 홀수, 짝수 분리
        if (index % 2 == 0) {
            if (*iter == 2) {
                count[1] += 1;
            }
        } else if (*iter == SECOND_ANSWER[(index / 2) % 4]) {
            count[1] += 1;
        }
        
        // 3번 학생
        if (*iter == THIRD_ANSWER[(index / 2) % 5]) {
            count[2] += 1;
        }
        
        index++;
    }
    
    int max = 0;
    for (int i = 0; i < 3; i++) {
        if (count[i] > max) {
            max = count[i];
        }
    }
    
    vector<int> answer;
    for (int i = 0; i < 3; i++) {
        if (count[i] == max) {
            answer.push_back(i + 1);
        }
    }
    return answer;
}
