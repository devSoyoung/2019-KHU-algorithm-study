#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/*
��ȭ��ȣ���� ó������ ������ �Ȱ��� �� �ִ��� Ž���Ѵ�.
(�ִٸ� �ٷ� false ����)

ù��° �Ŷ� ù��°�� ������ ��ü
���ٸ�
�ι�° �Ŷ� �ι�° ������ ��ü
���ٸ�
....

������ ���� �Ŀ��� ���ٸ� true����
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