//Time taken : 30 minutes
//Given an n x n matrix of digits (0–9), find the number of unique paths from top-left to bottom-right, such that the sum of digits on the path is divisible by 7. You can only move right or down.
#include<iostream>
using namespace std; 

int countpaths(int i, int j, int sum, int n, int *matrix) {
    if (i >= n || j >= n) // Out of bounds check
        return 0;
        sum = sum + matrix[i*n + j];
    if (i == n-1 && j == n-1)
    {
        if (sum%7==0)
            return 1; 
        else
            return 0; 
    }


    return countpaths(i+1, j, sum, n, matrix) + countpaths(i, j+1, sum, n, matrix);
}

int main(void) {
    int matrix[5][5] = {
        {1, 2, 3, 4, 5},
        {0, 1, 1, 1, 1},
        {2, 2, 2, 2, 2},
        {3, 3, 3, 3, 3},
        {4, 4, 4, 4, 4}
    };

    int c = countpaths(0, 0, 0, 5, &matrix[0][0]); 
    cout << "This program ran to give you: " << c; 
}
