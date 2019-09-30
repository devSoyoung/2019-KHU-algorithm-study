#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    vector<int> times;
    int length = progresses.size();
    for(int i = 0; i < length; i++)
        times.push_back((int)((100 - progresses[i]) / speeds[i]) + 1);

    while(!times.empty()) {
        int count = 1;
        int min = times[0];
        times.erase(times.begin());
        while(!times.empty() && times[0] <= min) {
            count++;
            times.erase(times.begin());
        }
        answer.push_back(count);
    }

    return answer;
}