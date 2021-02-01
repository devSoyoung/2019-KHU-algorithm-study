#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;

    int length = prices.size();
    for(int i = 0; i < length; i++) {
        int count = 0;
        for(int j = 0; j < length - i - 1; j++) {
            count++;
            if(prices[i + j + 1] < prices[i])
                break;
        }
        answer.push_back(count);
    }

    return answer;
}