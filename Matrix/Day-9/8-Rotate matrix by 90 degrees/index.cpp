// T.C: O(n^2) and S.C : O(1)

#include <bits/stdc++.h>
using namespace std;

// Function to rotate matrix anticlockwise by 90 degrees.
void rotateby90(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int mid;
    if (n % 2 == 0)
        mid = n / 2 - 1;
    else
        mid = n / 2;
    for (int i = 0, j = n - 1; i <= mid; i++, j--)
    {
        for (int k = 0; k < j - i; k++)
        {
            swap(matrix[i][j - k], matrix[j][i + k]); // ru ld
            swap(matrix[i + k][i], matrix[j][i + k]); // lu ld
            swap(matrix[i][j - k], matrix[j - k][j]); // ru rd
        }
    }
}

void printMatrix(vector<vector<int>> &arr)
{

    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{

    vector<vector<int>> arr = {{1, 2, 3, 4},
                               {5, 6, 7, 8},
                               {9, 10, 11, 12},
                               {13, 14, 15, 16}};
    rotateby90(arr);
    printMatrix(arr);
    return 0;
}
