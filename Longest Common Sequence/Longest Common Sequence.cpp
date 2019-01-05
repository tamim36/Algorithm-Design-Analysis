#include <bits/stdc++.h>
using namespace std;

int LCS(char x[], char y[], int xLength, int yLength)
{
    int matrix[xLength+1][yLength+1];

    for (int i=0; i<=xLength; i++){
        for (int j=0; j<=yLength; j++){
            if (i==0 || j==0){
                matrix[i][j] = 0;
            }
            else if (x[i-1] == y[j-1])
                matrix[i][j] = matrix[i-1][j-1] + 1;
            else
                matrix[i][j] = max(matrix[i-1][j], matrix[i][j-1]);
        }
    }
    int lcslength=matrix[xLength][yLength];
    int index = lcslength;
    int i = xLength;
    int j = yLength;
    char lcsString[lcslength];

    while (i>0 && j>0){
        if (x[i-1] == y[j-1]){
        lcsString[index-1] = x[i-1];
        --i;
        --j;
        --index;
        }
    else if (matrix[i-1][j] > matrix[i][j-1])
        --i;
    else
        --j;
    }
    for (i=0; i<lcslength; i++){
        cout << lcsString[i];
    }
    cout << endl;

    return lcslength;
}
int max(int a,int b){ (a>b)? a:b; }

int main()
{
    char x[] = "abcdef";
    char y[] = "abcfghijk";
    int xLength = strlen(x);
    int yLength = strlen(y);
    printf("Length of LCS is: %d\n",LCS(x,y,xLength,yLength));
    return 0;
}
