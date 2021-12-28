using namespace std;

#include <iostream>
#include <vector>

class RemoveDuplicates {
 public:
  static int remove(vector<int>& arr) {
    // TODO: Write your code here
    int pos = 0;
    int latestValue = arr[0];
    for (int value = 1; value < arr.size(); value++) {
        if (arr[value] != latestValue) {
            pos++;
            arr[pos] = arr[value];
            latestValue = arr[pos];
        }
    }
    return pos+1;
  }
};


int main(int argc, char* argv[]) {
  vector<int> arr = {2, 3, 3, 3, 6, 9, 9};
  cout << "Array new length: " << RemoveDuplicates::remove(arr) << endl;

  arr = vector<int>{2, 2, 2, 11};
  cout << "Array new length: " << RemoveDuplicates::remove(arr) << endl;
}