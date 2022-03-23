// NOTE : In the below implementation, maximum digits in the output are assumed as 500. To find a factorial of a much larger number ( > 254), increase the size of an array or increase the value of MAX. from gfg

// https://iq.opengenus.org/factorial-of-large-numbers/#:~:text=Time%20Complexity%3A%20O(n%20log%20n!)&text=1)!%E2%8C%89-,(base%2010).,steps%20required%20will%20be%20four.
// C++ program to compute factorial of big numbers

// T.C: O(n log n!)
// S.C: O(⌈log n!⌉)


#include <iostream>
using namespace std;
#define MAX 1000

int multiplyx(int x, int ans[], int size)
{
    int carry = 0;
    for (int i = 0; i < size; i++)
    {
        int product = ans[i] * x + carry;
        ans[i] = product % 10;
        carry = product / 10;
    }

    while (carry)
    {
        ans[size] = carry % 10;
        carry = carry / 10;
        size++;
    }
    return size;
}

void factorial(int n)
{
    int ans[MAX];
    ans[0] = 1;
    int size = 1;
    for (int x = 2; x <= n; x++)
        size = multiplyx(x, ans, size);

    cout << "Factorial of given number is: \n";
    for (int i = size - 1; i >= 0; i--)
        cout << ans[i];
}

int main()
{

    int n;
    cout << "Enter any larger number: " << endl;
    cin >> n;
    factorial(n);
    return 0;
}
