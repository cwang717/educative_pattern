using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>

class CircularArrayLoop {
 public:
  static bool loopExists(const vector<int> &arr) {
    // TODO: Write your code here
    unordered_map<int, bool> record;
    for (int i=0; i < arr.size(); i++) {
        if (record.find(i) == record.end()) {
            if (searchLoop(arr, i, record)) {
                return true;
            }
        } 
    }
    return false;
  }

 private:
  static bool searchLoop(const vector<int> &arr, int i, unordered_map<int, bool> &record) {
      int slow = i, fast = i;
      do {
        slow = next(arr, slow, record);
        fast = next(arr, next(arr, fast, record), record);
        if (arr[i]*arr[slow] < 0 || arr[i]*arr[fast] < 0) {
            return false;
        }
      } while (slow != fast);
      return true;
  }

  static int next(const vector<int> &arr, int i, unordered_map<int, bool> &record) {
      int nextIndex = (i + arr[i]) % arr.size();
      record[nextIndex] = true;
      return nextIndex;
  }
};

int main(int argc, char *argv[]) {
  cout << CircularArrayLoop::loopExists(vector<int>{1, 2, -1, 2, 2}) << endl;
  cout << CircularArrayLoop::loopExists(vector<int>{2, 2, -1, 2}) << endl;
  cout << CircularArrayLoop::loopExists(vector<int>{2, 1, -1, -2}) << endl;
}