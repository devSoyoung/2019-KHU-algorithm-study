#include <string>
#include <vector>
#include <iostream>
using namespace std;

/*
장르를 보관하는 벡터 생성
장르의 총합을 표현하는 벡터 생성
장르의 최대값을 저장하는 벡터 생성(index, play)
장르의 두번째 값을 저장하는 벡터 생성(index, play)

0. 모든 배열의 값이 비어있을 때 까지 반복한다.
1. 새로운 장르인지 파악
(새로운 장르라면 장르벡터에 추가한다. 최댓값과 두번째 값에는 0 저장)
2. 최댓값과 비교해서 더 크면, 해당 값을 최댓값에 넣고 두번째 값에 최댓값을 넣는다.
2-1. 더 작다면, 해당 값과 두번 째 값을 비교하고 크다면 교체, 아니라면 아무 동작도 하지 않는다.
3. 해당 장르의 총합 벡터에 해당 값을 추가한다.
4. genres에서 제거한다.


4. 총합이 큰 순으로 answer에 추가한다. 두번 째 값이 0인 경우 출력하지 않는다.

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