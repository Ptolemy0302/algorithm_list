#include <cstdio>
#include <iostream>

using namespace std;
#define MAX 100

int A[MAX]; //定义存放二叉树用的数组

int LAC(int x, int y)
{
    int result = A[0];//至少会返回根结点的值
    bool left = false, right = false;//用以确认当前节点的左右子树是否包含x和y
    if(x<y)
        return result;
    
    return result;
}

int main()
{
    
    int x, y;
    scanf("%d %d", x, y); //定义用以判断祖先的两点

    int n;
    scanf("%d", n); //定义真实子树长度

    for (int i = 0; i < n; i++)
        scanf("%d", A[i]); //传入二叉树数组信息

    //int A[13] = {1, 2, 3, 0, 4, 5, 6, 0, 0, 0, 0, 7, 8};

    printf("LAC(%d, %d) = %d", x, y, LAC(x, y)); //输出最小共同祖先
    return 0;
}