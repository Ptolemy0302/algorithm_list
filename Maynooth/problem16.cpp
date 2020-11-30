#include <cstdio>
#include <iostream>

using namespace std;
#define LEN 13//定义数组长度

int A[LEN] = {1, 2, 3, 0, 4, 5, 6, 0, 0, 0, 0, 7, 8}; //定义存放二叉树用的数组

bool LAC(int n, int x, int y)
{
    bool left = false, right = false; //用以确认当前节点的左右子树是否包含x和y
    int flag = false;
    if (n < LEN)
    {
        left = LAC(2 * n + 1, x, y);
        right = LAC(2 * n + 2, x, y);

        /*以下四个条件满足两个，即为最小共同祖先；仅满足一个，则为共同祖先的某子树；此外，则不在共同祖先子树下*/
        if(left==true)
            flag++;
        if(right==true)
            flag++;
        if(A[n]==x)
            flag++;
        if(A[n]==y)
            flag++;

        if(flag==2){
            printf("LAC(%d, %d) = %d", x, y, A[n]); //输出最小共同祖先
            return false;
        }else if(flag==1)
            return true;
        else
            return false;
    }

    return false;
}

int main()
{

    //int x, y;
    //scanf("%d %d", x, y); //定义用以判断祖先的两点

    //int n;
    //scanf("%d", n); //定义真实子树长度

    //for (int i = 0; i < n; i++)
    //    scanf("%d", A[i]); //传入二叉树数组信息

    LAC(0, 1, 8); //输出最小共同祖先。以1和8为例
    return 0;
}