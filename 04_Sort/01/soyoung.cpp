#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    const int length = commands.size();
    for (int i = 0; i < length; i++) {
        // 배열 자르기
        vector<int> subArray;
        const int startIdx = commands[i][0] - 1;
        const int endIdx = commands[i][1];
        for (int j = startIdx; j < endIdx; j++) {
            subArray.push_back(array[j]);
        }
        
        // 정렬하기
        sort(subArray.begin(), subArray.end());
        const int targetIdx = commands[i][2] - 1;
        answer.push_back(subArray[targetIdx]);
    }
    return answer;
}