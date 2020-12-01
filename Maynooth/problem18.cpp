#include <cstdio>
#include <iostream>
#define LEN 4

int N = 8;
int S[LEN] = {1, 3, 5, 7};
int T[100] = {0}; //保存答案

using namespace std;
void showNum(int temp, int test, int n)
{
    for (int i = temp; i < LEN; i++)
    {
        if (S[i] + n == N)
        {
            //T[test] = S[i];
            int j = 1;
            printf("{ %d", T[0]);
            while (T[j] != 0)
            {
                printf(", %d", T[j]);
                j++;
            }
            printf(" }");
            printf("\n");
            T[test] = 0;
            return;
        }
        else if (S[i] + n < N)
        {
            T[test] = S[i];
            showNum(i, test + 1, S[i] + n);
        }
        else
            break;
    }
}

int main()
{
    //scanf("%d", N);
    showNum(0, 0, 0);

    return 0;
}