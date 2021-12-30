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

class InsertInterval {
 public:
  static vector<Interval> insert(const vector<Interval> &intervals, Interval newInterval) {
    vector<Interval> mergedIntervals;
    // TODO: Write your code here
    Interval temp = Interval(0, 0);
    bool noTemp = true, doneMerge = false;
    for (auto interval:intervals) {
        if (doneMerge) {
            mergedIntervals.push_back(interval);
            continue;
        }

        if (noTemp) {
            if (interval.end < newInterval.start) {
                mergedIntervals.push_back(interval);
                continue;
            }
            
            if (interval.start > newInterval.end) {
                mergedIntervals.push_back(newInterval);
                mergedIntervals.push_back(interval);
                doneMerge = true;
                continue;
            }

            temp.start = min(newInterval.start, interval.start);
            temp.end = max(newInterval.end, interval.end);
            noTemp = false;
        } else {
            if (interval.start > temp.end) {
                mergedIntervals.push_back(temp);
                mergedIntervals.push_back(interval);
                doneMerge = true;
                continue;
            }

            temp.start = min(temp.start, interval.start);
            temp.end = max(temp.end, interval.end);
        }
    }

    if (! doneMerge) {
        mergedIntervals.push_back(temp);
    }
    return mergedIntervals;
  }
};

int main(int argc, char *argv[]) {
  vector<Interval> input = {{1, 3}, {5, 7}, {8, 12}};
  cout << "Intervals after inserting the new interval: ";
  for (auto interval : InsertInterval::insert(input, {4, 6})) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;

  cout << "Intervals after inserting the new interval: ";
  for (auto interval : InsertInterval::insert(input, {4, 10})) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;

  input = {{2, 3}, {5, 7}};
  cout << "Intervals after inserting the new interval: ";
  for (auto interval : InsertInterval::insert(input, {1, 4})) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;
}