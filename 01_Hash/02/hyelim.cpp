#include <string>
#include <vector>
using namespace std;

bool solution(vector<string> phone_book) {
    int length = phone_book.size();
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            if (i != j && phone_book[i].length() <= phone_book[j].length()) {
                if (phone_book[j].find(phone_book[i]) == 0)
                    return false;
            }
        }
    }
    return true;
}
