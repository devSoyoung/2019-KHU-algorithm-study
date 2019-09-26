#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    // 작업이 완료(100%)되는 날짜를 모두 계산
    const int progressLength = progresses.size();
    queue<int> completeDates;
    for (int i = 0; i < progressLength; i++) {
        int calculated = ((100 - progresses[i]) / speeds[i]);
        if ((100 - progresses[i]) % speeds[i] != 0) {
            calculated++;
        }
        completeDates.push(calculated);
    }
    
    // queue를 돌면서 배포 가능 기능 수 카운트
    vector<int> answer;
    while(!completeDates.empty()) {
        int featureCount = 0;
        const int currentCompleteDate = completeDates.front();
        while(currentCompleteDate >= completeDates.front()) {
            completeDates.pop();
            featureCount++;
            
            if (completeDates.empty()) {
                break;
            }
        }
        answer.push_back(featureCount);
    }
    return answer;
}