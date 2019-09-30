#include <string>
#include <vector>
#include <utility>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer(prices.size());
	stack<pair<int, int>> s; // pair(first: price, second: index)
	for (int i = 0; i < prices.size(); i++) {
		while (!s.empty() && s.top().first > prices[i]) { // 가격이 떨어졌을 때
			pair<int, int> top = s.top();
			s.pop();
			answer[top.second] = i - top.second; // index 차
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
	사실 굳이 pair로 <가격,index> 할 필요 없이 index를 stack에 넣으면 더 메모리를 아낄 수 있었다 ..
	prices[index]로 바로 가격은 구할 수 있으니까 ..!
*/