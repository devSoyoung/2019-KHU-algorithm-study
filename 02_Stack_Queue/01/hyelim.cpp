#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;

    int length = priorities.size();
    deque<pair<int, int>> queue;
    for (int i = 0; i < length; i++)
        queue.push_back(make_pair(i, priorities[i]));

    int count = 0;
    while(1) {
        bool check = true;
        pair<int, int> temp = queue.at(0);
        int comparand = temp.second;
        for (deque<pair<int, int>>::iterator iter = queue.begin(); iter < queue.end(); iter++) {
            if (comparand < (*iter).second) {
                queue.pop_front();
                queue.push_back(temp);
                check = false;
                break;
            }
        }

        if (check) {
            queue.pop_front();
            count++;
            if (temp.first == location) {
                answer = count;
                break;
            }
        }
    }

    return answer;
}
