using namespace std;

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

class TripletSumCloseToTarget {
 public:
  static int searchTriplet(vector<int>& arr, int targetSum) {
    // TODO: Write your code here
    int difference = numeric_limits<int>::max(); 
    sort(arr.begin(), arr.end());
    for (int left = 0; left < arr.size()-2; left++) {
        searchPairs(arr, targetSum-arr[left], left+1, difference);
        while (arr[left+1] == arr[left]) {
            left++;
        }
    }
    return targetSum + difference;
  }

 private:
  static void searchPairs(const vector<int> &arr, int target, int left, int &difference) {
    int subLeft = left, subRight = arr.size() - 1;
    while (subRight > subLeft) {
        int distance = arr[subRight] + arr[subLeft] - target;
        if (distance == 0) {
            difference = 0;
            return;
        }
        if (distance > 0) {
            if (abs(distance) < abs(difference)) {
                difference = distance;
            }
            subRight--;
        } else {
            if (abs(distance) < abs(difference)) {
                difference = distance;
            }
            subLeft++;
        }
    }
  }
};


int main(int argc, char* argv[]) {
  vector<int> vec = {-2, 0, 1, 2};
  cout << TripletSumCloseToTarget::searchTriplet(vec, 2) << endl;
  vec = {-3, -1, 1, 2};
  cout << TripletSumCloseToTarget::searchTriplet(vec, 1) << endl;
  vec = {1, 0, 1, 1};
  cout << TripletSumCloseToTarget::searchTriplet(vec, 100) << endl;
}
