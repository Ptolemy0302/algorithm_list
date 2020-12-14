#include <cstdio>
#include <iostream>

using namespace std;

#define N 9 //给定的数组长度

int arr[N] = {-7, -5, -3, -1, 1, 4, 6, 8, 9};

void judge(int x)
{
    int left = 0;
    int right = N;
    int floor = -999;
    int ceil = -999;
    int mid = 0;

    if (x < arr[0])
        ceil = arr[0];
    else if (x > arr[N - 1])
        floor = arr[N - 1];
    else
    {
        while (left < right)
        {
            mid = left + (right - left) / 2;
            if (arr[mid] == x) //存在与输入数字相同数时
            {
                floor = x;
                ceil = x;
                break;
            }
            else if (arr[mid] < x)
                left = mid + 1;
            else
                right = mid - 1;
        }
        floor = arr[mid - 1];
        ceil = arr[mid];
    }

    printf("floor(%d) = %d and ceil(%d) = %d", x, floor, x, ceil);
}

int main()
{
    int number = 0;
    cin >> number;
    //输入待判断数字
    judge(number); //进行判断，输出天花板数（数组中比该数大的最小值）和地板数（数组中比该数小的最大值）
    return 0;
}