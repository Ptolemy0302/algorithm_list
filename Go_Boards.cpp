#include <cstdio>
#include <iostream>

using namespace std;

#define MAX 50
char chessboard[MAX][MAX];
int evaboard[MAX][MAX];
int N = 0;
int answer = 0;

bool chess(int x, int y)
{
    if (x > N || y > N || x < 1 || y < 1) //越界格
        return 1;

    if (chessboard[x][y] == 'x') //检查是否原本为黑子
    {
        evaboard[x][y] = 1;
        return 1;
    }

    if (chessboard[x][y] == '.' && evaboard[x][y] == 0) //若为未检查过的空格
    {
        int judge = 0;
        if (chessboard[x + 1][y] == 'o')
            judge++;
        if (chessboard[x - 1][y] == 'o')
            judge++;
        if (chessboard[x][y + 1] == 'o')
            judge++;
        if (chessboard[x][y - 1] == 'o')
            judge++;
        evaboard[x][y] = judge;
        if (evaboard[x][y] > 1) //当前格子是否适合落子
        {
            answer--;
            return 1;
        }
        else
            return 0;
    }

    if (evaboard[x][y] == 1) //若为已检查过的空格
        return 0;
    else
        return 1;
}

void regret(int x, int y)
{
    if (x > N || y > N || x < 1 || y < 1) //越界格或原本就为黑棋
        return;

    if (chessboard[x][y] == '.') //检查是否原本为黑子
    {
        evaboard[x][y]--;
        if (evaboard[x][y] == 1)
        {
            answer++;
            if (evaboard[x + 1][y + 1] < 1 && evaboard[x + 1][y + 1] < 1 && evaboard[x + 1][y + 1] < 1 && evaboard[x + 1][y + 1] < 1)
                answer--;
        }
    }
}

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> chessboard[i][j];
            if (chessboard[i][j] == '.')
                answer++;
        }
    }

    int temp;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (chessboard[i][j] == 'o')
            {
                temp = chess(i + 1, j) + chess(i - 1, j) + chess(i, j + 1) + chess(i, j - 1); //检测当前白子相邻黑子所返回的结果
                if (temp == 4)                                                                //判断当前白子是否会被吞并，具体需要扣除的棋子数
                {
                    answer++;
                }
                else
                {
                    regret(i + 1, j);
                    regret(i - 1, j);
                    regret(i, j + 1);
                    regret(i, j - 1);
                }
            }
            cout << answer;
        }
        cout << '\n';
    }

    return 0;
}
