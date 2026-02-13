#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

using namespace std;

void drawStars(int n, int y, int x, vector<vector<char>>& board)
{
    if (n == 1)
    {
        board[y][x] = '*';
        return;
    }

    int size = n / 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == 1 && j == 1) continue;
            drawStars(size, y + i * size, x + j * size, board);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<vector<char>> board(n, vector<char>(n, ' '));

    drawStars(n, 0, 0, board);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j];
        }
        cout << '\n';
    }

    return 0;
}