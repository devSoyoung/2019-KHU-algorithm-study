#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/*
전화번호부의 처음부터 끝까지 똑같은 게 있는지 탐색한다.
(있다면 바로 false 리턴)

첫번째 거랑 첫번째를 제외한 전체
없다면
두번째 거랑 두번째 이후의 전체
없다면
....

끝까지 수행 후에도 없다면 true리턴
*/


bool solution(vector<string> phone_book) {
	for (int i = 0; i < phone_book.size(); i++) {
		for (int j = i + 1; j < phone_book.size(); j++) {
			if (phone_book[j].size() > phone_book[i].size()) {
				if (phone_book[j].find(phone_book[i]) == 0)
					return false;
			}
			else {
				if (phone_book[i].find(phone_book[j]) == 0)
					return false;
			}
		}
	}
	return true;
}

void main() {

	vector<string> good = { "119", "97674223", "1195524421" };
	cout << solution(good);
	
}