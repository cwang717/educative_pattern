using namespace std;

#include <iostream>
#include <vector>

class MissingNumber {
 public:
  static int findMissingNumber(vector<int> &nums) {
    // TODO: Write your code here
    int result = -1;
    int index = 0;
    while (index < nums.size()) {
        while (nums[index] != nums.size() && nums[index] != index) {
            swap(nums, index, nums[index]);
        }
        if (nums[index] == nums.size()) {
            result = index;
        }
        ++index;
    }
    return result;
  }

 private:
  static void swap(vector<int> &nums, int a, int b) {
      int temp = nums[a];
      nums[a] = nums[b];
      nums[b] = temp;
  }
};


int main(int argc, char *argv[]) {
  vector<int> v1 = {4, 0, 3, 1};
  cout << MissingNumber::findMissingNumber(v1) << endl;
  v1 = {8, 3, 5, 2, 4, 6, 0, 1};
  cout << MissingNumber::findMissingNumber(v1) << endl;
}