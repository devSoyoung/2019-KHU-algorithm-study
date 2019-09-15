#include <string>
#include <vector>
//#include <string.h>
using namespace std;

#define totalSize 100000

int myhash(const string &key, int tableSize) {
    int hashVal = 0;

    int length = key.length();
    for (int i = 0; i < length; i++)
        hashVal += 13 * hashVal + key[i];

    hashVal %= tableSize;

    if (hashVal < 0)
        hashVal += tableSize;

    return hashVal;
}

string solution(vector<string> participant, vector<string> completion) {
    string answer;

    int hashmap[totalSize]= {0, };
    //int hashmap[100000];
    //memset(hashmap, 0, sizeof(int) * 100000);

    int length = completion.size();
    for (int i = 0; i < length; i++)
        hashmap[myhash(completion[i], totalSize)]++;

    length++;
    for (int j = 0; j < length; j++) {
        int res = myhash(participant[j], totalSize);
        hashmap[res]--;
        if (hashmap[res] == -1) {
            answer = participant[j];
            break;
        }
    }

    return answer;
}
