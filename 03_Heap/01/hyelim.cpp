#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

	int length = scoville.size();
	priority_queue< int, vector<int>, greater<int> > queue;
	for (int i = 0; i < length; i++)
		queue.push(scoville[i]);

	bool check = true;
	int a = queue.top();
	int b;
	while (a < K) {
		if (length >= 2) {
			queue.pop();
			b = queue.top();
			queue.pop();
			queue.push(a + b * 2);
			a = queue.top();
			answer++;
			length--;
		}
		else
			check = false;
	}

	return (check? answer: -1);
}
