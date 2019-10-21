#include <string>
#include <vector>
#include<numeric>
using namespace std;

int answer = 0;
void DFS(int target, vector<int> numbers, int index) {
    if (index == numbers.size()) {
        int result = accumulate(numbers.begin(), numbers.end(), 0);
        if (result == target) {
            answer++;
        }
        return;
    }
    
    DFS(target, numbers, index + 1);
    
    numbers[index] *= -1;
    DFS(target, numbers, index + 1);
}

int solution(vector<int> numbers, int target) {
    DFS(target, numbers, 0);
    return answer;
}
