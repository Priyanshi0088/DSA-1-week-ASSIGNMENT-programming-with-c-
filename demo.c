#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        nums[i] = nums[i] * nums[i];
    }

    sort(nums.begin(), nums.end());

    return nums;
}

int main() {
    vector<int> nums = {-4, -1, 0, 3, 10};

    vector<int> result = sortedSquares(nums);

    cout << "Output: ";
    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}