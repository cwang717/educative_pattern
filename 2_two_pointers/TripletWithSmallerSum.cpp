using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class TripletWithSmallerSum {
 public:
  static int searchTriplets(vector<int> &arr, int target) {
    int count = 0;
    // TODO: Write your code here
    sort(arr.begin(), arr.end());
    for (int left = 0; left < arr.size() - 2; left++) {
        // cout << left << ": ";
        count += searchPairs(arr, target-arr[left], left+1);
    }
    return count;
  }

 private:
  static int searchPairs(const vector<int> &arr, int target, int left) {
    int subLeft = left, subRight = arr.size() - 1;
    int count = 0;
    while (subRight > subLeft) {
        if (arr[subRight] + arr[subLeft] >= target) {
            subRight--;
        } else {
            count += subRight - subLeft;
            subLeft++;
        }
    }
    // cout << count << endl;
    return count;
  }
};


int main(int argc, char *argv[]) {
  vector<int> vec = {-1, 0, 2, 3};
  cout << TripletWithSmallerSum::searchTriplets(vec, 3) << endl;
  vec = {-1, 4, 2, 1, 3};
  cout << TripletWithSmallerSum::searchTriplets(vec, 5) << endl;
}