using namespace std;

#include <iostream>
#include <queue>
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

class EmployeeFreeTime {
 public:
  
  struct compareStarttime {
      bool operator() (const pair<Interval, pair<int,int>> &i1, const pair<Interval, pair<int,int>> &i2) {
          return i1.first.start > i2.first.start;
      }
  };

  static vector<Interval> findEmployeeFreeTime(const vector<vector<Interval>> &schedule) {
    vector<Interval> result;
    // TODO: Write your code here
    priority_queue<pair<Interval, pair<int, int>>, 
                   vector<pair<Interval, pair<int, int>>>, 
                   compareStarttime> minHeap;
    for (int k = 0; k < schedule.size(); k++) {
        minHeap.push(make_pair(schedule[k][0], make_pair(k, 0)));
    }


    while (!minHeap.empty()) {
        int previousEndtime = minHeap.top().first.end;
        pair<int, int> popIDs = minHeap.top().second;
        if (popIDs.second + 1 < schedule[popIDs.first].size()) {
            minHeap.push(make_pair(schedule[popIDs.first][popIDs.second+1], 
                                   make_pair(popIDs.first, popIDs.second+1)));
        }
        minHeap.pop();
        if (previousEndtime < minHeap.top().first.start) {
            result.push_back(Interval(previousEndtime, minHeap.top().first.start));
        }
    }

    return result;
  }
};

int main(int argc, char *argv[]) {
  vector<vector<Interval>> input = {{{1, 3}, {5, 6}}, {{2, 3}, {6, 8}}};
  vector<Interval> result = EmployeeFreeTime::findEmployeeFreeTime(input);
  cout << "Free intervals: ";
  for (auto interval : result) {
    cout << "[" << interval.start << ", " << interval.end << "] ";
  }
  cout << endl;

  input = {{{1, 3}, {9, 12}}, {{2, 4}}, {{6, 8}}};
  result = EmployeeFreeTime::findEmployeeFreeTime(input);
  cout << "Free intervals: ";
  for (auto interval : result) {
    cout << "[" << interval.start << ", " << interval.end << "] ";
  }
  cout << endl;

  input = {{{1, 3}}, {{2, 4}}, {{3, 5}, {7, 9}}};
  result = EmployeeFreeTime::findEmployeeFreeTime(input);
  cout << "Free intervals: ";
  for (auto interval : result) {
    cout << "[" << interval.start << ", " << interval.end << "] ";
  }
}
