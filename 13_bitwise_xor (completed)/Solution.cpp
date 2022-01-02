#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    static vector<vector<int>> flipAndInvertImage(vector<vector<int>> arr) {
      //TODO: Write your code here
      for (vector<int> &v: arr) {
          for (int i = 0; i < (v.size()+1)/2; i++) {
              int temp = v[i] ^ 1;
              v[i] = v[v.size()-1-i] ^ 1;
              v[v.size()-1-i] = temp;
          } 
      }
      return arr;
    }

    static void print(const vector<vector<int>> arr) {
      for(int i=0; i < arr.size(); i++) {
        for (int j=0; j < arr[i].size(); j++) {
          cout << arr[i][j] << " ";
        }
        cout << endl;
      }
    }
};

int main(int argc, char* argv[]) {
  vector<vector<int>> arr = vector<vector<int>>{{1, 0, 1}, {1, 1, 1}, {0, 1, 1}};
  Solution::print(Solution::flipAndInvertImage(arr));
  cout << endl;

  vector<vector<int>> arr2 = vector<vector<int>>{{1,1,0,0},{1,0,0,1},{0,1,1,1},{1,0,1,0}};
  Solution::print(Solution::flipAndInvertImage(arr2));
}