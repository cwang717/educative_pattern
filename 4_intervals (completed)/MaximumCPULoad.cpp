using namespace std;

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

class Job {
 public:
  int start = 0;
  int end = 0;
  int cpuLoad = 0;

  Job(int start, int end, int cpuLoad) {
    this->start = start;
    this->end = end;
    this->cpuLoad = cpuLoad;
  }
};

class MaximumCPULoad {
 public:
  struct compareEnd {
      bool operator() (const Job &j1, const Job &j2) {
          return j1.end > j2.end;
      }
  };
  
  static int findMaxCPULoad(vector<Job> &jobs) {
    // TODO: Write your code here
    sort(jobs.begin(), jobs.end(), 
         [](const Job &j1, const Job &j2) {return j1.start < j2.start;});
    
    priority_queue<Job, vector<Job>, compareEnd> minHeap;
    int maxLoad = 0, currentLoad = 0;
    for (auto j:jobs) {
        while (!minHeap.empty() && minHeap.top().end <= j.start) {
            currentLoad -= minHeap.top().cpuLoad;
            minHeap.pop();
        }
        minHeap.push(j);
        currentLoad += j.cpuLoad;
        maxLoad = max(maxLoad, currentLoad);
    }

    return maxLoad;
  }
};

int main(int argc, char *argv[]) {
  vector<Job> input = {{1, 4, 3}, {7, 9, 6}, {2, 5, 4}};
  cout << "Maximum CPU load at any time: " << MaximumCPULoad::findMaxCPULoad(input) << endl;

  input = {{6, 7, 10}, {8, 12, 15}, {2, 4, 11}};
  cout << "Maximum CPU load at any time: " << MaximumCPULoad::findMaxCPULoad(input) << endl;

  input = {{1, 4, 2}, {3, 6, 5}, {2, 4, 1}};
  cout << "Maximum CPU load at any time: " << MaximumCPULoad::findMaxCPULoad(input) << endl;
}
