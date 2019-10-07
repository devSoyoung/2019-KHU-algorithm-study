#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct compare {
    bool operator()(string s1, string s2) {
        int firstNum = stoi(s1 + s2);
        int secondNum = stoi(s2 + s1);
        if (firstNum > secondNum) {
            return false;
        } else {
            return true;
        }
    }
};

string solution(vector<int> numbers) {
    priority_queue<string, vector<string>, compare> pq;
    string temp;
    for (int i = 0; i < numbers.size(); i++) {
        temp = to_string(numbers[i]);
        pq.push(temp);
    }
    
    string answer = "";
    int size = pq.size();
    for (int i = 0; i < size; i++) {
        answer += pq.top();
        pq.pop();
    }
    
    // 한 번이라도 0이 아닌게 나오면 정답 그대로 출력
    for (int i = 0; i < answer.size(); i++) {
        if (answer[i] != '0') {
            return answer;
        }
    }
    return "0";
}
