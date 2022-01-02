using namespace std;

#include <iostream>
#include <vector>

class TwoSingleNumbers {
public:
  static vector<int> findSingleNumbers(vector<int> &nums) {
    // TODO: Write your code here
    int twoXOR = 0;
    for (auto a:nums) {
        twoXOR ^= a;
    }

    int rightMost = 1;
    while ((rightMost & twoXOR) == 0) {
        rightMost  = rightMost << 1;
    }
    
    int num1 = 0, num2 = 0;
    for (auto a:nums) {
        if ((a & rightMost) == 0) {
            num1 ^= a;
        } else {
            num2 ^= a;
        }
    }

    return num1 < num2 ? vector<int>{num1, num2} : vector<int>{num2, num1};
  }
};

int main(int argc, char *argv[]) {
  vector<int> v1 = {1, 4, 2, 1, 3, 5, 6, 2, 3, 5};
  vector<int> result = TwoSingleNumbers::findSingleNumbers(v1);
  cout << "Single numbers are: " << result[0] << ", " << result[1] << endl;

  v1 = {2, 1, 3, 2};
  result = TwoSingleNumbers::findSingleNumbers(v1);
  cout << "Single numbers are: " << result[0] << ", " << result[1] << endl;
}
