#include <iostream>
#include <windows.h>
#include <vector>

using namespace std;

void removeAndSort(vector<int>& nums) {
    int index = 0;

    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] % 2 != 0) {
            nums[index] = nums[i];
            index++;
        }
    }

    nums.resize(index);

    for (int i = 0; i < index - 1; ++i) {
        for (int j = 0; j < index - i - 1; ++j) {
            if (nums[j] < nums[j + 1]) {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
}
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n;
    cout << "Введіть кількість елиментів: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Введіть елименти: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    removeAndSort(nums);

    cout << "Результат: ";
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
