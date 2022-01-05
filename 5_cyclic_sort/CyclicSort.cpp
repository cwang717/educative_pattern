using namespace std;

#include <iostream>
#include <vector>

class CyclicSort {
 public:
  static void sort(vector<int> &nums) {
    // TODO: Write your code here 
    int index = 0;
    while (index < nums.size()) {
        while (nums[index] != index+1) {
            swap(nums, index, nums[index]-1);
        }
        ++index;
    }

    for (auto a:nums) {
        cout << a << " ";
    }
    cout << endl;
  }

 private:
  static void swap(vector<int> &nums, int a, int b) {
      int temp = nums[a];
      nums[a] = nums[b];
      nums[b] = temp;
  }
};


int main(int argc, char *argv[]) {
  vector<int> arr = {3, 1, 5, 4, 2};
  CyclicSort::sort(arr);

  arr = vector<int>{2, 6, 4, 3, 1, 5};
  CyclicSort::sort(arr);


  arr = vector<int>{1, 5, 6, 4, 3, 2};
  CyclicSort::sort(arr);

}