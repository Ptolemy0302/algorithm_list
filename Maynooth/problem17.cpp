#include <cstdio>
#include <iostream>

using namespace std;
#define Len 15 //所需长度为26，测试用例长度为15

//int A[Len] = {1, 2, 3, 8, 4, 5, 6, 0, 0, 10, 0, 7, 9, 10, 1, 0, 0, 0, 0, 1, 2, 0, 0, 0, 5, 2};
int A[Len] = {1, 2, 3, 8, 4, 5, 6, 0, 0, 10, 0, 7, 9, 0, 5};
int B[Len] = {0}; //存放每步计算后的答案

int FindM(int n)//检查当前结点的左右节点的值后，加上最大值并返回
{
    int left, right;
    if (n < Len)
    {
        int value = A[n];
        left = FindM(2 * n + 1);
        right = FindM(2 * n + 2);
        if (left > right)
            value += left;
        else
            value += right;

        if (value > B[n])
            B[n] = value;
        return value;
    }
    else
        return 0;
}

int main()
{
    printf("The maximum sum is %d an the maximum sum path is [", FindM(0));
    int i = 0;
    while (B[i] != 0)
    {
        if (B[2 * i + 1] > B[2 * i + 2])
        {
            printf("%d", B[i] - B[2 * i + 1]);
            i = 2 * i + 1;
        }
        else
        {
            printf("%d", B[i] - B[2 * i + 2]);
            i = 2 * i + 2;
        }
        if (B[i] != 0)
            printf(",");
    }
    printf("].");
    return 0;
}