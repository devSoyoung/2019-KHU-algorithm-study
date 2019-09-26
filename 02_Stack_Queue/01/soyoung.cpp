#include <string>
#include <queue>
#include <vector>
using namespace std;

// 출력되는 순서대로 queue에 집어넣자
// location에 해당하는 아이템이 들어갔을 때, queue의 사이즈가 답이다.
int solution(vector<int> priorities, int location) {
    const int length = priorities.size();
    queue<int> itemQueue;
    for(int i = 0; i < length; i++) {
        itemQueue.push(priorities[i]);
    }
    
    int count = 0;
    while(!itemQueue.empty()) {
        int currentMax = 1;
        int queueSize = itemQueue.size();
        // 현재 가장 높은 우선순위 확인
        for (int j = 0; j < queueSize; j++) {
            int currentItem = itemQueue.front();
            itemQueue.pop();
            itemQueue.push(currentItem);
            if (currentItem > currentMax) {
                currentMax = currentItem;
            }
        }
        
        // 현재 아이템이랑 비교
        if (itemQueue.front() == currentMax) {
            itemQueue.pop();
            count++;
            if (location == 0) {
                // 현재 아이템이 location인 경우: 현재 카운트 반환
                return count;
            } else {
                // 현재 아이템이 location이 아닌 경우
                // 출력 횟수를 올리고, location을 한 칸 앞으로 당김
                location--;
            }
        } else {
            const int currentValue = itemQueue.front();
            itemQueue.pop();
            itemQueue.push(currentValue);
            
            if (location == 0) {
                location = itemQueue.size() - 1;
            } else {
                location--;
            }
        }
    }
}