#include <string>
#include <vector>
using namespace std;

void quicksort(int*& data, int start, int end) {
    if (start >= end)
        return;

    int pivot = start;
    int i = pivot + 1;
    int j = end;
    int temp;

    while (i <= j) {
        while (i <= end && data[i] <= data[pivot])
            i++;
        while (j > start && data[j] >= data[pivot])
            j--;

        if (i > j)
            swap(data[pivot], data[j]);
        else
            swap(data[i], data[j]);
    }

    quicksort(data, start, j - 1);
    quicksort(data, j + 1, end);
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    int num = commands.size();
    for (int i = 0; i < num; i++) {
        int size = commands[i][1] - commands[i][0] + 1;
        int* data = new int[size];
        for (int j = 0; j < size; j++)
            data[j] = array[commands[i][0] - 1 + j];

        quicksort(data, 0, size - 1);

        answer.push_back(data[commands[i][2]-1]);
    }

    return answer;
}
