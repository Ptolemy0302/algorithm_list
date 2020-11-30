#include <cstdio>
#include <iostream>
#define LEN 3

int N = 4;
int S[LEN] = {1, 2, 3};
int B[LEN][LEN + 1] = {{0}}; //保存答案,便于进行筛选
int C[LEN + 1] = {0};            //保存临时答案

using namespace std;
void showNum(int num, int n)
{
    for (int i = 0; i < 3; i++)
    {
        if (S[i] + n == N)
        {
            for (int i = 0;i<LEN;i++){
                if(B[i][0] == C[0])//比较两种方案是否一样
                {

                }
                else if(B[i][0]==0)//新增方案
                {

                }
            }

            if (B[0][0] = 0)
            {
                if (B[C[i]] == 0)
                {
                    B[i][C[i]]++;
                    B[i][0]++;
                }
                else
                {
                    B[i][C[i]]++;
                }
            }
            return;
        }
        else if (S[i] + n < N)
        {
            C[i]++;
            showNum(num + 1, (S[i] + n));
        }
        else
            break;
    }
}

int main()
{
    //scanf("%d", N);
    showNum(0, 0);

    int i = 0;
    B[i][0] = S[i];
    int j = 1;
    printf("{ %d", B[0]);
    while (B[j] != 0)
    {
        printf(", %d", B[j]);
        j++;
    }
    printf(" }");
    printf("\n");
    return 0;
}