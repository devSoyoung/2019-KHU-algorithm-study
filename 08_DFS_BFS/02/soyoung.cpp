#include <string>
#include <vector>
#include <queue>
using namespace std;

bool visited[200] = { false, };
int answer = 0;

void check(int index, vector<vector<int>>& computers, int length) {
    if (visited[index]) return;
    visited[index] = true;
    
    for (int i = 0; i < length; i++) {
        if (visited[i]) continue;
        if (computers[index][i] == 1)
            check(i, computers, length);
    }
}

int solution(int n, vector<vector<int>> computers) {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            answer++;
            check(i, computers, n);
        }
    }
    return answer;
}
