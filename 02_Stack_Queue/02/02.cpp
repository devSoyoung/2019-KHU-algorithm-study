
/*
0. 0��° �迭�� 0�ְ� ���� ū���� 0��° �� �Է�.

1. ���±��� �� ���� ū �� �ľ�(���� �� �ִ� �� �����Ǵ�)
2. ū���������� �� ��ġ�������� ����ġ������ ū �༮��� �̷���� �迭 ����(�ڼ��� ��ġ �ľ�)
3. �ű⼭ index�� ���� ū �� ����.
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
