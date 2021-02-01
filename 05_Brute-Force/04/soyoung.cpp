#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int brown, int red) {
    vector<int> answer;
    // 브라운의 최소 가로/세로 길이가 3
    const int size =  brown + red;
    
    for (int i = 3; i <= size; i++) {
        // 현재 수로 나누어 떨어지지 않으면 pass
        if (size % i != 0) {
            continue;
        }
        
        // 전체 가로, 세로 크기 지정
        int width = max(i, size / i);
        int height = min(i, size / i);
        
        // 현재 brown을 중심으로 red 유효성 검사
        if ((width - 2) * (height - 2) >= red) {
            answer.push_back(width);
            answer.push_back(height);
            break;
        }
    }
    return answer;
}
