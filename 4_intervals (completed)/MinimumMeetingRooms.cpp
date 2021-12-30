using namespace std;

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

class Meeting {
 public:
  int start = 0;
  int end = 0;

  Meeting(int start, int end) {
    this->start = start;
    this->end = end;
  }
};

class MinimumMeetingRooms {
 public:
  struct compareEndtime {
      bool operator() (const Meeting &m1, const Meeting &m2) {
        return m1.end > m2.end;
      }
  };

  static int findMinimumMeetingRooms(vector<Meeting> &meetings) {
    // TODO: Write your code here
    sort(meetings.begin(), meetings.end(), [](const Meeting &m1, const Meeting &m2){return m1.start < m2.start;});
    priority_queue<Meeting, vector<Meeting>, compareEndtime> q;
    int maxCount = 0;
    for (auto m:meetings) {
        while ((!q.empty()) && q.top().end <= m.start) {
            q.pop();
        }
        q.push(m);
        maxCount = max(maxCount, (int)q.size());
    }
    return maxCount;
  }
};

int main(int argc, char *argv[]) {
  vector<Meeting> input = {{4, 5}, {2, 3}, {2, 4}, {3, 5}};
  int result = MinimumMeetingRooms::findMinimumMeetingRooms(input);
  cout << "Minimum meeting rooms required: " << result << endl;

  input = {{1, 4}, {2, 5}, {7, 9}};
  result = MinimumMeetingRooms::findMinimumMeetingRooms(input);
  cout << "Minimum meeting rooms required: " << result << endl;

  input = {{6, 7}, {2, 4}, {8, 12}};
  result = MinimumMeetingRooms::findMinimumMeetingRooms(input);
  cout << "Minimum meeting rooms required: " << result << endl;

  input = {{1, 4}, {2, 3}, {3, 6}};
  result = MinimumMeetingRooms::findMinimumMeetingRooms(input);
  cout << "Minimum meeting rooms required: " << result << endl;

  input = {{4, 5}, {2, 3}, {2, 4}, {3, 5}};
  result = MinimumMeetingRooms::findMinimumMeetingRooms(input);
  cout << "Minimum meeting rooms required: " << result << endl;
}
