using namespace std;

#include <iostream>

class HappyNumber {
 public:
  static bool find(int num) {
    // TODO: Write your code here
    int fast = num, slow = num;
    do {
        fast = next(next(fast));
        slow = next(slow);
    } while (slow != fast);
    if (fast == 1) {
        return true;
    }
    return false;
  }

 private:
  static int next(int num) {
      div_t div_result;
      int result = 0;
      do {
          div_result = div(num, 10);
          result += div_result.rem * div_result.rem;
          num = div_result.quot;
      } while (div_result.quot != 0);
      return result;
  }
};

int main(int argc, char* argv[]) {
  cout << HappyNumber::find(23) << endl;
  cout << HappyNumber::find(12) << endl;
}
