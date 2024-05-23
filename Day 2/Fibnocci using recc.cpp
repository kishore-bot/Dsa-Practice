vector<int> generateFibonacciNumbers(int n)
{
    vector<int> fibNumbers;
    if (n <= 0)
    {
        return fibNumbers;
    }
    // Base cases
    if (n == 1)
    {
        fibNumbers.push_back(0);
        return fibNumbers;
    }
    else if (n == 2)
    {
        fibNumbers.push_back(0);
        fibNumbers.push_back(1);
        return fibNumbers;
    }
    // Recursive case
    fibNumbers = generateFibonacciNumbers(n - 1);                // Generate Fibonacci numbers up to n-1
    fibNumbers.push_back(fibNumbers[n - 2] + fibNumbers[n - 3]); // Calculate and add the nth Fibonacci number
    return fibNumbers;
}