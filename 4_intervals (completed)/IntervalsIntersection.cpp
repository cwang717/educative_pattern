using namespace std;

#include <iostream>
#include <vector>

class Interval {
 public:
  int start = 0;
  int end = 0;

  Interval(int start, int end) {
    this->start = start;
    this->end = end;
  }
};

class IntervalsIntersection {
 public:
  static vector<Interval> merge(const vector<Interval> &arr1, const vector<Interval> &arr2) {
    vector<Interval> result;
    // TODO: Write your code here
    int j = 0;
    for (int i = 0; i < arr1.size(); i++) {
        while ( arr1[i].start > arr2[j].end && j <arr2.size()) {
            j++;
        }
        if (j == arr2.size()) {
            break;
        }
        if (arr1[i].end < arr2[j].start) {
            continue;
        }
        result.push_back(Interval(max(arr1[i].start, arr2[j].start), 
                                  min(arr1[i].end, arr2[j].end)));
    }

    return result;
  }
};

int main(int argc, char *argv[]) {
  vector<Interval> input1 = {{1, 3}, {5, 6}, {7, 9}};
  vector<Interval> input2 = {{2, 3}, {5, 7}};
  vector<Interval> result = IntervalsIntersection::merge(input1, input2);
  cout << "Intervals Intersection: ";
  for (auto interval : result) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;

  input1 = {{1, 3}, {5, 7}, {9, 12}};
  input2 = {{5, 10}};
  result = IntervalsIntersection::merge(input1, input2);
  cout << "Intervals Intersection: ";
  for (auto interval : result) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
}
