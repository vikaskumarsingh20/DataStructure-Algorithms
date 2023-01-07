class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        // n>0, +ve int and , n= 4-> 100 ,n-1 ->010 n*n-1 -> 000 which is power of two
        return (n > 0 and (n & (n - 1)) == 0);
    }
};