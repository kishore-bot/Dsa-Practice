// Medium
// BIT MAGIC
// https://www.naukri.com/code360/problem-of-the-day/moderate



// https://www.youtube.com/watch?v=N3dtzMKJMn8
int getSum(int a, int b)
{
    int carry, sum;
    while (carry != 0)
    {
        sum = a ^ b;
        carry = (a & b) << 1;
        a = sum;
        b = carry;
    }
    return sum;
}