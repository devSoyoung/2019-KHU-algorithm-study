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

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    int hashmap[1000];
    memset(hashmap, 0, sizeof(int) * 1000);
    int length = clothes.size();
    for(int i = 0; i < length; i++) {
        hashmap[myhash(clothes[i][1], 1000)]++;
    }

    for(int i = 0; i < 1000; i++) {
        if(hashmap[i] != 0)
            answer *= (hashmap[i] + 1);
     }

    return (answer - 1);
}
