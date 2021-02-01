#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int solution(vector<int> citations) {
    // 내림차순으로 정렬
    sort(citations.begin(), citations.end(), greater<int>());
    const int length = citations.size();
    for (int i = 0; i < length; i++) {
        if (i >= citations[i]) {
            return i;
        }
    }
}