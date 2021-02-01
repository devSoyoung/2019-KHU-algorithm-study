#include string
#include vector
#include algorithm
using namespace std;


int solution(vectorint priorities, int location) {
    int answer = 0;
    while(true) {
        if (priorities[0] == max_element(priorities.begin(), priorities.end())) {
            answer++;
            priorities.erase(priorities.begin());
            if (location == 0)
                break;
        }
        else {
            priorities.push_back(priorities.begin());
            priorities.erase(priorities.begin());
            if (location == 0)
                location = priorities.size();
        }
        location--;
    }
    return answer;
}