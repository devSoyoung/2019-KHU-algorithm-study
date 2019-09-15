#include <string>
#include <vector>
#include <string.h>
using namespace std;

int myhash(const string &key, int tableSize) {
	int hashVal = 0;

	for (int i = 0; i < key.length(); i++)
		hashVal = 37 * hashVal + key[i];

	hashVal %= tableSize;

	if (hashVal < 0)
		hashVal += tableSize;

	return hashVal;
}

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    int hashmap[100000]= {0, };
    //int hashmap[100000];
	//memset(hashmap, 0, sizeof(int) * 100000);

	int length = completion.size();
	for (int i = 0; i < length; i++)
		hashmap[myhash(completion[i], 100000)]++;

	length++;
	for (int j = 0; j < length; j++) {
		int res = myhash(participant[j], 100000);
		hashmap[res]--;
		if (hashmap[res] == -1) {
			answer = participant[j];
			break;
		}
	}

	return answer;
}
