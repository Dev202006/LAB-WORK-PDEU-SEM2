//SUDOKU VALIDATOR
/*
00-01-02 
10-11-12
20-21-22

30-31-32
40-41-42 ...
51-51-52

60-61-62
70-71-72
81-81-82



*/
#include<iostream>

using namespace std; 

bool isValidSudoku(int *sudoku); 
int main(void)
{
    int solvedSudoku[9][9] = {
    {5, 3, 4, 6, 7, 8, 9, 1, 2},
    {6, 7, 2, 1, 9, 5, 3, 4, 8},
    {1, 9, 8, 3, 4, 2, 5, 6, 7},
    {8, 5, 9, 7, 6, 1, 4, 2, 3},
    {4, 2, 6, 8, 5, 3, 7, 9, 1},
    {7, 1, 3, 9, 2, 4, 8, 5, 6},
    {9, 6, 1, 5, 3, 7, 2, 8, 4},
    {2, 8, 7, 4, 1, 9, 6, 3, 5},
    {3, 4, 5, 2, 8, 6, 1, 7, 9}
};
    bool result = isValidSudoku(&solvedSudoku[0][0]);
    if(result)
        cout<<"The sudoku is solved";
    else
        cout<<"The sudoku is unsolved";


}
bool isValidSudoku(int *sudoku)
{
    //assumes n = 9
    /*Returns true if : 
    1. 1-9 unique elements in the column , row 
    2. 1-9 unique elments in the subarray    
    */
    //returns zero directly if any array or column has any repeating element 
    for(int i =0;i<9;i++)
    {
        int count[9];
        for(int j =0;j<9;j++)
        {
            //traversing row first
            count[j] = sudoku[i*9 +j]; 

        }
        //check if it's repeating
        for(int k =0;k<9;k++)
        {
            for(int m=0;m<9;m++)
            {
            if(k!=m)
            {
                if(count[k]==count[m])
                {
                    return false;
                }
            }
        }
        }
    }
    for(int i =0;i<9;i++)
    {
        int count[9]={0,0,0,0,0,0,0,0,0};
        for(int j =0;j<9;j++)
        {
            //traversing column first
            count[j] = sudoku[j*9 +i]; 
        }
        //check if it's repeating
        for(int k =0;k<9;k++)
        {
            for(int m=0;m<9;m++)
            {
            if(k!=m)
            {
                if(count[k]==count[m])
                {
                    return false;
                }
            }
        }
        }
    }
    //to check the third condition
  for (int boxRow = 0; boxRow < 3; boxRow++) {
    for (int boxCol = 0; boxCol < 3; boxCol++) {
        int count[9] = {0};
        int idx = 0;
        for (int i = boxRow * 3; i < boxRow * 3 + 3; i++) {
            for (int j = boxCol * 3; j < boxCol * 3 + 3; j++) {
                count[idx++] = sudoku[i * 9 + j];
            }
        }
        // check for duplicates
        for (int k = 0; k < 9; k++) {
            for (int m = k + 1; m < 9; m++) {
                if (count[k] == count[m]) return false;
            }
        }
    }
}   

    return true;


}