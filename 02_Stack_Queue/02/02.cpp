
/*
0. 0번째 배열에 0넣고 가장 큰수로 0번째 수 입력.

1. 여태까지 중 가장 큰 수 파악(보낼 수 있는 지 여부판단)
2. 큰수에서부터 현 위치까지에서 현위치값보다 큰 녀석들로 이루어진 배열 생성(자세한 위치 파악)
3. 거기서 index가 가장 큰 놈 추출.
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    int max_index = 0;
    answer.push_back(0);
    for (int i = 1; i < heights.size() ; i++) {
        if (heights[max_index] <= heights[i])
        {
            answer.push_back(0);
            max_index=i;
        }

        for (int j = i - 1; j >=  max_index; j--) {
            if(heights[i] < heights[j])
            {
                answer.push_back(j+1);
                break;
            }
        }

    }
    return answer;
}
