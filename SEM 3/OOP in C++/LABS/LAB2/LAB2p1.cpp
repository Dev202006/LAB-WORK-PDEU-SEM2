//addition and multiplication of matrices

#include<iostream>

using namespace std;
void printmatrix(int *matrix,int n);

int main(void)
{
    int n;
    // by default makes multiplicable matrices
    cout<<"Enter number of rows: ";
    cin>>n;
    int matrix1[n][n];
    int matrix2[n][n];
    int added[n][n];
    int multi[n][n];

    //reading two matrices
    for(int i =0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<endl<<"Enter element ("<<i<<","<<j<<"): ";
            cin>>matrix1[i][j];
        }
    }
    for(int i =0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<"Enter element ("<<i<<","<<j<<"): ";
            cin>>matrix2[i][j];
        }
    }
    //printing original matrix
    printmatrix(&matrix1[0][0],n);
    printmatrix(&matrix2[0][0],n);

    //adding the elements:
    for(int i =0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            added[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    //multiplication
    for(int i =0;i<n;i++)
    {
        for (int k =0;k<n;k++)
        {
            int sum = 0;
            for (int j =0;j<n;j++)
            {
                sum = sum + matrix1[i][j]*matrix2[j][k];
            }
            multi[i][k]=sum;
        }

    }
    cout<<"Matrix of the suM: "<<endl;
    printmatrix(&added[0][0],n);
    cout<<endl<<"Matrix of the multiplication: "<<endl;
    printmatrix(&multi[0][0],n);

}
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
