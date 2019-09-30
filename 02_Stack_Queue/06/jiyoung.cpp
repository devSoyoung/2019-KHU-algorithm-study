#include <string>
#include <vector>
#include <utility>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer(prices.size());
	stack<pair<int, int>> s; // pair(first: price, second: index)
	for (int i = 0; i < prices.size(); i++) {
		while (!s.empty() && s.top().first > prices[i]) { // ������ �������� ��
			pair<int, int> top = s.top();
			s.pop();
			answer[top.second] = i - top.second; // index ��
		}
		s.push(make_pair(prices[i], i));
	}

	while (!s.empty()) {
		pair<int, int> top = s.top();
		s.pop();
		answer[top.second] = prices.size() - top.second - 1;
	}

	return answer;
}

/*
	��� ���� pair�� <����,index> �� �ʿ� ���� index�� stack�� ������ �� �޸𸮸� �Ƴ� �� �־��� ..
	prices[index]�� �ٷ� ������ ���� �� �����ϱ� ..!
*/