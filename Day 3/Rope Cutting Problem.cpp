// Medium
// https://www.geeksforgeeks.org/batch/dsa-4/track/DSASP-Recursion/video/MjMzMw%3D%3D
// Recurson

int cutRope(int n, int a, int b, int c)
{
    if (n == 0)
        return 0;
    if (n < 0)
        return -1;
    int res = max(cutRope(n - a, a, b, c), max(cutRope(n - b, a, b, c), cutRope(n - c, a, b, c)));
    if (res == -1)
        return -1;
    return res + 1;
}