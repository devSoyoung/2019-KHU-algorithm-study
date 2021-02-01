#include <string>
#include <vector>
#include <iostream>
using namespace std;

/*
�帣�� �����ϴ� ���� ����
�帣�� ������ ǥ���ϴ� ���� ����
�帣�� �ִ밪�� �����ϴ� ���� ����(index, play)
�帣�� �ι�° ���� �����ϴ� ���� ����(index, play)

0. ��� �迭�� ���� ������� �� ���� �ݺ��Ѵ�.
1. ���ο� �帣���� �ľ�
(���ο� �帣��� �帣���Ϳ� �߰��Ѵ�. �ִ񰪰� �ι�° ������ 0 ����)
2. �ִ񰪰� ���ؼ� �� ũ��, �ش� ���� �ִ񰪿� �ְ� �ι�° ���� �ִ��� �ִ´�.
2-1. �� �۴ٸ�, �ش� ���� �ι� ° ���� ���ϰ� ũ�ٸ� ��ü, �ƴ϶�� �ƹ� ���۵� ���� �ʴ´�.
3. �ش� �帣�� ���� ���Ϳ� �ش� ���� �߰��Ѵ�.
4. genres���� �����Ѵ�.


4. ������ ū ������ answer�� �߰��Ѵ�. �ι� ° ���� 0�� ��� ������� �ʴ´�.

*/


vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	vector<string> new_genre;
	bool is_new = true;
	vector<int> genre_play;
	vector<int> biggest_in_genre[2];
	vector<int> second_in_genre[2];
	int cnt = 0;
	while (!genres.empty()) {
		int i = 0;
		is_new = true;
		for (; i < new_genre.size(); i++) {
			if (genres[0] == new_genre[i]) {
				is_new = false;
				break;
			}
		}
		if (is_new) {
			new_genre.push_back(genres[0]);
			biggest_in_genre[0].push_back(-1);
			biggest_in_genre[1].push_back(0);
			second_in_genre[0].push_back(-1);
			second_in_genre[1].push_back(0);
			genre_play.push_back(0);
		}

		if (biggest_in_genre[1][i] < plays[0]) {
			second_in_genre[0][i] = biggest_in_genre[0][i];
			second_in_genre[1][i] = biggest_in_genre[1][i];
			biggest_in_genre[0][i] = cnt;
			biggest_in_genre[1][i] = plays[0];
		}
		else {
			if (second_in_genre[1][i] < plays[0]) {
				second_in_genre[0][i] = cnt;
				second_in_genre[1][i] = plays[0];
			}
		}

		genre_play[i] += plays[0];
		genres.erase(genres.begin());
		plays.erase(plays.begin());
		
		cnt++;
	}

	vector<int> order;
	int biggest_num = 0;
	int biggest_index = 0;
	for(int j = 0 ; j < genre_play.size() ; j++) {
		int i = 0;
		for (; i < genre_play.size(); i++) {
			if (biggest_num < genre_play[i]) {
				biggest_num = genre_play[i];
				biggest_index = i;
			}
		}
		order.push_back(biggest_index);
		
		genre_play[biggest_index] = 0;
		biggest_num = 0;
		biggest_index = 0;
	}
	for (int i = 0; i < order.size(); i++) {
		answer.push_back(biggest_in_genre[0][order[i]]);
		if (second_in_genre[0][order[i]] != -1)
			answer.push_back(second_in_genre[0][order[i]]);
	}
	return answer;
}

void main() {

	vector<string> genres = { "classic", "pop", "classic", "classic", "pop" };
	vector<int> plays = { 2500, 600, 150, 1800, 2500 };

	vector<int> end = solution(genres, plays);

	while (!end.empty()) {
		cout << end[0] << endl;
		end.erase(end.begin());
	}
}