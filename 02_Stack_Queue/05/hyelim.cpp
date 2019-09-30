#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(string arrangement) {
    int answer = 0;

    stack<int> pipes;
    int length = arrangement.length();
    for(int i = 0; i < length; i++) {
        if(arrangement[i] == '(') {
            if(arrangement[i + 1] == ')') {
                // 레이저
                int size = pipes.size();
                stack<int> temp;
                for(int j = 0; j < size; j++) {
                    temp.push(pipes.top() + 1);
                    pipes.pop();
                }
                for(int j = 0; j < size; j++) {
                    pipes.push(temp.top());
                    temp.pop();
                }
                i++;
                continue;
            } else {
                // 파이프 시작
                pipes.push(1);
            }
        } else {
            // 파이프 끝
            answer += pipes.top();
            pipes.pop();
        }
    }

    return answer;
}