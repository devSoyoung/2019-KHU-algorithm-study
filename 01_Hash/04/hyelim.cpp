#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define totalSize 5000

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

class Playlist {
private:
    int num;
    priority_queue<pair<int, int>> songs;
    
public:
    Playlist(int num) {
        this->num = num;
    }
    
    void addSong(pair<int, int> newSong) {
        songs.push(newSong);
    }
    
    int getNum() {
        return num;
    }
    
    int getMaxSong() {
        if(songs.empty())
            return -1;
        
        int maxSong = songs.top().second;
        songs.pop();
        return maxSong;
    }
};

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    Playlist* hashmap[totalSize];
    for(int i = 0; i < totalSize; i++)
        hashmap[i] = NULL;
    
    int length = genres.size();
    int count = 0;
	for (int i = 0; i < length; i++) {
        int hashGenre = myhash(genres[i], totalSize);
        if(hashmap[hashGenre] == NULL) {
            Playlist* newPlaylist = new Playlist(hashGenre);
            hashmap[hashGenre] = newPlaylist;
            count++;
        }
        hashmap[hashGenre]->addSong(make_pair(plays[i], i));
    }
    
    for(int i = 0; i < count; i++) {
        int max = 0;
        int num = 0;
        for(int j = 0; j < totalSize; j++) {
            if(hashmap[j] != NULL && hashmap[j]->getNum() > max) {
                max = hashmap[j]->getNum();
                num = j;
            }
        }
        
        for(int j = 0; j < 2; j++) {
            int maxSong = hashmap[num]->getMaxSong();
            if(maxSong != -1)
                answer.push_back(maxSong);
        }
        
        hashmap[num] = NULL;
    }
    
    return answer;
}