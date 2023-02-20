#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int **tab;

struct Queen
{
    int row;
    int col;
};
vector<Queen> queensResult;
int result = INT_MAX;

bool solve(int n, vector<vector<int>> &board, vector<Queen> &queens, int row, int tempResult)
{
    if ((int)queens.size() == n)
    {

        queensResult = queens;
        result = tempResult;
        return true;
    }

    for (int i = 0; i < n; i++)
    {
        if (tab[row][i] == 0)
        {
            if (tempResult + board[row][i] < result)
            {
                queens.push_back({row, i});

                for (int j = row; j < n; j++)
                {
                    tab[j][i]++;
                }
                for (int j = row, k = 0; j < n; j++, k++)
                {
                    if (i - k >= 0)
                        tab[j][i - k]++;
                }
                for (int j = row, k = 0; j < n; j++, k++)
                {
                    if (i + k < n)
                        tab[j][i + k]++;
                }
                solve(n, board, queens, row + 1, tempResult + board[row][i]);
                queens.pop_back();

                for (int j = row; j < n; j++)
                {
                    tab[j][i]--;
                }
                for (int j = row, k = 0; j < n; j++, k++)
                {
                    if (i - k >= 0)
                        tab[j][i - k]--;
                }
                for (int j = row, k = 0; j < n; j++, k++)
                {
                    if (i + k < n)
                        tab[j][i + k]--;
                }
            }
        }
    }

    return false;
}

int main()
{

    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    vector<Queen> queens;

    int n;
    cin >> n;
    tab = new int *[n];

    for (int i = 0; i < n; i++)
    {
        tab[i] = new int[n];

        for (int j = 0; j < n; j++)
        {
            tab[i][j] = 0;
        }
    }

    vector<vector<int>> board(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }
    solve(n, board, queens, 0, 0);

    for (Queen q : queensResult)
    {
        cout << q.col << " ";
    }

    return 0;
}