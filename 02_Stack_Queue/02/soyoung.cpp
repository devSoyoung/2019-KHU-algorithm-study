#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    const int length = heights.size();
    for (int i = 0; i < length; i++) {
        if (i == 0) {
            answer.push_back(0);
            continue;
        }
        
        // 앞의 탑 비교
        for (int j = i; j >= 0; j--) {
            // 앞의 탑이 높이가 더 높을 경우: 수신
            if (heights[j] > heights[i]) {
                answer.push_back(j + 1);
                break;
            }
            
            // 마지막까지 더 높은 탑이 없을 경우: 0 표시
            if (j == 0) {
                answer.push_back(0);
            }
        }
    }
    return answer;
}