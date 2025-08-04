
// rotate a matrix by 90 degree

#include<iostream>
using namespace std;

void printmatrix(int *matrix,int n)
{
    for (int i =0;i<n;i++)
    {
        for(int j =0;j<n;j++)
        {
            cout<<matrix[i*n + j]<<'\t';
        }
        cout<<endl;
    }
}
int main(void)
{
    int n;
    cout<<"Enter number of rows: ";
    cin>>n;
    int matrix[n][n];
    //reading matrix
    for(int i =0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<endl<<"Enter element ("<<i<<","<<j<<"): ";
            cin>>matrix[i][j];
        }
    }
    //formula: i =  n-1-j; j = i
    int transpose[n][n];
    for (int i=0;i<n;i++)
    {
        for(int j =0;j<n;j++)
        {
            transpose[i][j]=matrix[j][i];
        }
    }
    printmatrix(&transpose[0][0],n);
    int reverse[n][n];
    for (int i=0;i<n;i++)
    {
        for(int j =0;j<n;j++)
        {
            reverse[i][j]=transpose[i][n-1-j];
        }
    }
    cout<<endl<<"final: ";
    printmatrix(&reverse[0][0],n);

}
