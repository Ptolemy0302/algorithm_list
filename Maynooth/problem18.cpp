#include <cstdio>
#include <iostream>

int S[3] = {1, 2, 3};
int N = 4;
int B[10] = {}; //保存答案

using namespace std;
void showNum(int num, int n)
{
    for (int i = 0; i < 3; i++)
    {
        if (S[i] + n == N)
        {
            B[num] = S[i];
            int j = 1;
            printf("{ %d", B[0]);
            while (B[j] != 0)
            {
                printf(", %d", B[j]);
                j++;
            }
            printf(" }");
            printf("\n");
            B[num] = 0;
            return;
        }
        else if (S[i] + n < N)
        {
            B[num] = S[i];
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
    return 0;
}