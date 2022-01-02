using namespace std;

#include <iostream>
#include <limits>
#include <vector>

class ShortestWindowSort {
 public:
  static int sort(const vector<int>& arr) {
    // TODO: Write your code here
    int left = 0, right = arr.size()-1;
    while (left < right) {
        if (arr[left]>arr[left+1]) {
            break;
        } else {
            left++;
        }
    }

    while (left < right) {
        if (arr[right] < arr[right-1]) {
            break;
        } else {
            right--;
        }
    }

    if (left==right) {
        return 0;
    }

    int minValue = arr[left+1], maxValue = arr[right-1];
    for (int i = left; i<right+1; i++) {
        minValue = min(minValue, arr[i]);
        maxValue = max(maxValue, arr[i]);
    } 

    while (left > 0) {
        if (arr[left-1] <= minValue) {
            break;
        } else {
            left--;
        }
    }

    while (right < arr.size()-1) {
        if (arr[right+1] >= maxValue) {
            break;
        } else {
            right++;
        }
    }
    return right - left + 1;
  }
};

int main(int argc, char* argv[]) {
  cout << ShortestWindowSort::sort(vector<int>{1, 2, 5, 3, 7, 10, 9, 12}) << endl;
  cout << ShortestWindowSort::sort(vector<int>{1, 3, 2, 0, -1, 7, 10}) << endl;
  cout << ShortestWindowSort::sort(vector<int>{1, 2, 3}) << endl;
  cout << ShortestWindowSort::sort(vector<int>{3, 2, 1}) << endl;
}