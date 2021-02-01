#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> check;
   
    const int completionLength = completion.size();
    for (int i = 0; i < completionLength; i++) {
        // 없으면 새로 생성하기
        if (check.find(completion[i]) == check.end()) {
            check.insert(make_pair(completion[i], 1));
            continue;
        }
        // 이미 있는 key면 1 증가시키기
        check[completion[i]] += 1;
    }
    
    const int participantLength = participant.size();
    for (int j = 0; j < participantLength; j++) {
        // 없으면 해당 참가자 이름을 반환
        if (check.find(participant[j]) == check.end()) {
            return participant[j];
        }
        
        if (check[participant[j]] == 0) {
            return participant[j];
        }
        
        check[participant[j]] -= 1;
    }
}