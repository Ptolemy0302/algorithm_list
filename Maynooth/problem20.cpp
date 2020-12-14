#include <cstdio>
#include <iostream>

using namespace std;

int arr[9] = {-7, -5, -3, -1, 1, 4, 6, 8, 9};

void judge(int x)
{
    int i = 0;
    int floor = -999;
    int ceil = -999;
    while (i < 9)
    {
        if (arr[i] == x) //存在与输入数字相同数时
        {
            floor = x;
            ceil = x;
            break;
        }
        else if (arr[i] < x)
            i++;
        else
        {
            ceil = arr[i];
            if (i - 1 > -1)
                floor = arr[i - 1];          
            break;
        }
    }
    if(ceil==-999)//如果该数大于数组中所有数
        floor = arr[i - 1];
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