#include <iostream>

using namespace std;

class CalculateComplement {
    public:
     static int bitwiseComplement(int n) {
        // TODO: Write your code here
        int allBitSet = 1;
        int temp = n;
        while ( (temp >> 1) != 0) {
            temp = temp >> 1;
            allBitSet = (allBitSet << 1) + 1; 
        }

        return n^allBitSet;
    }
};

int main(int argc, char* argv[]) {
  // your code goes here
  cout << "Bitwise complement is: " << CalculateComplement::bitwiseComplement(8) << endl;
  cout << "Bitwise complement is: " << CalculateComplement::bitwiseComplement(10) << endl;
}