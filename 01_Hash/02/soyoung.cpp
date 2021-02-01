#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    
    const int length = phone_book.size() - 1;
    for (int i = 0; i < length; i++) {
        if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].size()))
            return false;
    }
    return true;
}