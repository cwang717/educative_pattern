using namespace std;

#include <iostream>
#include <vector>

class DutchFlag {
 public:
  static void sort(vector<int> &arr) {
    // TODO: Write your code here 
    int left = 0, right = arr.size()-1;
    for (int i = 0; i < right + 1; ) {
        if (arr[i] == 0) {
            swap(arr, left++, i++);
        } else if (arr[i] == 2) {
            swap(arr, right--, i);
        } else {
            i++;
        }
    }
  }

 private:
  static void swap(vector<int> &arr, int x, int y) {
      int temp = arr[x];
      arr[x] = arr[y];
      arr[y] = temp;
  }
};

int main(int argc, char *argv[]) {
  vector<int> arr = {1, 0, 2, 1, 0};
  DutchFlag::sort(arr);
  for (auto num : arr) {
    cout << num << " ";
  }
  cout << endl;

  arr = vector<int>{2, 2, 0, 1, 2, 0};
  DutchFlag::sort(arr);
  for (auto num : arr) {
    cout << num << " ";
  }
}