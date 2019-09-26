#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 기존의 triangle을 업데이트 하면서 간다
// 양쪽 끝과 끝이 아닌 경우를 구분한다
int solution(vector<vector<int>> triangle) {
    const unsigned int length = triangle.size();
    // 삼각형 업데이트
    for (int i = 1; i < length; i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            if (j == 0) {
                // 제일 앞
                triangle[i][j] += triangle[i - 1][j];
            } else if (j == triangle[i].size() - 1) {
                // 제일 뒤
                triangle[i][j] += triangle[i - 1][j - 1];
            } else {
                // 양쪽 중에서 비교해서 더 큰 값으로 update
                if (triangle[i - 1][j - 1] > triangle[i - 1][j]) {
                    triangle[i][j] += triangle[i - 1][j - 1];
                } else {
                    triangle[i][j] += triangle[i - 1][j];
                }
            }
        }
    }
    
    // 제일 마지막 줄에서 가장 큰 값 찾기
    vector<int>::iterator answer = max_element(triangle.back().begin(), triangle.back().end());
    return *answer;
}