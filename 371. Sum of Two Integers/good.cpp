class Solution
{
public:
  int getSum(int a, int b)
  {
    while (b != 0)
    {
      int transfers = (unsigned int) (a & b) << 1;
      a = a ^ b; // calculate sum without transfers
      b = transfers;
    }
    return a;
    // a = 55;          110111
    // b = 44;          101100
    // (a & b);         100100
    // a ^ b;            11011

    // (a & b) << 1;   1001000
    // return          1100011
  }
};
