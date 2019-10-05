#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;

    int check = 0;
    int length = dates.size();
    priority_queue<int, vector<int>,less<int>> max_heap;
    for(int i = 0; i < k; i++) {
        if(check < length && dates[check] == i) {
            max_heap.push(supplies[check]);
            check++;
        }

        if(stock == 0) {
            stock += max_heap.top();
            max_heap.pop();
            answer++;
        }

        stock--;
    }

    return answer;
}