#include <string>
#include <vector>
#include <cmath>
#include <string.h>
using namespace std;

bool* check;

bool isPrimeNumber(int number) {
    bool isPrime = true;
    for (int i = 2; i <= number / 2; i++) {
        if(number % i == 0) {
            isPrime = false;
            break;
        }
    }
    return isPrime;
}

void bfs(vector<char> chars, string str, int count) {
	if (count != 0)
		check[stoi(str)] = true;

	int length = chars.size();
	for (int i = 0; i < length; i++) {
		string temp = str;
		temp += chars[i];
		vector<char> temp_chars = chars;
		chars.erase(chars.begin() + i);
		bfs(chars, temp, count + 1);
		bfs(chars, str, count);
		chars = temp_chars;
	}
}

int solution(string numbers) {
    int answer = 0;

	int length = numbers.length();
	vector<char> chars;
	for (int i = 0; i < length; i++)
		chars.push_back(numbers[i]);

	int size = pow(10, length);
	check = new bool[size];
	memset(check, false, sizeof(bool) * size);
	bfs(chars, "", 0);

	for (int i = 3; i < size; i++) {
		if (check[i] && isPrimeNumber(i))
			answer++;
	}

	return answer;
}