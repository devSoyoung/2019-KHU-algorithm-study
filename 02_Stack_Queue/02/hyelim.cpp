#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;

    answer.push_back(0);
    int length = heights.size();
    for (int i = 1; i < length; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (heights[j] > heights[i]) {
                answer.push_back(j + 1);
                break;
            }
            if (j == 0)
                answer.push_back(0);
        }
    }

    return answer;
}
