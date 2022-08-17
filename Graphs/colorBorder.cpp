class Solution
{
    void detectBorder(vector<vector<int>> &grid, int x, int y, int color)
    {
        grid[x][y] = -1 * grid[x][y];

        bool isEdge = false;
        int dx[] = {-1, 0, 0, +1};
        int dy[] = {0, -1, +1, 0};

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size() || abs(grid[nx][ny]) != color)
            {
                isEdge = true;
                continue;
            }

            if (grid[nx][ny] == color)
                detectBorder(grid, nx, ny, color);
        }

        if (!isEdge)
            grid[x][y] = color;

        return;
    }

public:
    vector<vector<int>> colorBorder(vector<vector<int>> &grid, int x, int y, int replace)
    {
        int color = grid[x][y];

        detectBorder(grid, x, y, color);
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
                if (grid[i][j] < 0)
                    grid[i][j] = replace;
        }

        return grid;
    }
};