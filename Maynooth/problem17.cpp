#include <cstdio>
#include <iostream>

using namespace std;

int B[10]; //存放答案；
int A[10];
// A[] = { 1, 2, 3, 8, 4, 5, 6, 0, 0, 10, 0, 7, 9, 10, 1, 0, 0, 0, 0, 1, 2, 0, 0, 0, 5, 2 };

int FindM(int n)
{
    int left, right;
    int value = A[n];

    if (A[n] != NULL)
    {
        left = FindM(2 * n + 1);
        right = FindM(2 * n + 2);
        if (left > right)
            value += left;
        else
            value += right;
    }

    return value;
}
//the maximum sum is 18 an the maximum sum path is [1, 3, 5, 9].

int main()
{
    int A[5];
    printf("the maximum sum is %d an the maximum sum path is [", FindM(0));
    int i = 0;
    while(B[i]!=0){
        printf("%d", B[i]);
        i++;
    }
    printf("]");

    return 0;
}