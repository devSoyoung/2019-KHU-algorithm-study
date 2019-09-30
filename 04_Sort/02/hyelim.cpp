#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Number {
    void setNumber(int input) {
        digit = 0;
        for(int i = 0; i < 6; i++) {
            if(input == 0)
                numbers.push_back(0);
            else {
                numbers.insert(numbers.begin(), input % 10);
                input /= 10;
                digit++;
            }
        }
    }
    
    string getNumber() {
        string str = "";
        
        for(int i = 0; i < digit; i++)
            str += (numbers[i] + '0');
        
        return str;
    }
    
        vector<int> numbers;
        int digit;
};

bool dfs(const Number &n1, const Number &n2, int count) {
	if (n1.numbers[count] < n2.numbers[count])
		return false;
	else if (n1.numbers[count] == n2.numbers[count]) {
		if (++count > n1.digit)
			return true;
		else if (count > n2.digit)
			return false;
		else
			return dfs(n1, n2, count);
	}
	else
		return true;
}

bool compare(const Number &n1, const Number &n2) {
	return dfs(n1, n2, 0);
}

string solution(vector<int> numbers) {
    string answer = "";
    
    int length = numbers.size();
    Number* nums = new Number[length];
    for(int i = 0; i < length; i++)
        nums[i].setNumber(numbers[i]);
    
    sort(nums, nums + length, compare);
    
    for(int i = 0; i < length; i++)
        answer += nums[i].getNumber();
    
    return answer;
}