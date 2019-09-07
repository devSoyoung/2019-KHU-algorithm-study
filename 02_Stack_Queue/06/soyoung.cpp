#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    const int length = prices.size();
    for (int i = 0; i < length; i++) {
        int count = 0;
        for (int j = i + 1; j < length; j++) {
            count++;
            if (prices[i] > prices[j]) break;
        }
        answer.push_back(count);
    }
    return answer;
}