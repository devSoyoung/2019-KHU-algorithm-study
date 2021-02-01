#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;

    sort(citations.begin(), citations.end(), greater<int>());

    int length = citations.size();
    for(; answer < length; answer++) {
        if(citations[answer] <= answer)
            break;
    }

    return answer;
}
