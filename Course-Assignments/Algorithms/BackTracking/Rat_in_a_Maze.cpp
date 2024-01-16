// You are given a starting position for a rat which is stuck in a maze at an initial point (0, 0) (the maze can be thought of as of 2-dimensional plane). The maze would be given in the form of a square matrix of order 'N' * 'N' where the cells with value 0 represent the maze's blocked locations while value 1 is the open/available path that the rat can take to reach its destination. The rat's destination is at ('N' - 1, 'N' - 1).
// Your task is to find all the possible paths that the rat can take to reach from source to destination in the maze. The possible directions that it can take to move in the maze are 'U' (up) i.e. (x, y - 1) , 'D'(down) i.e. (x, y + 1) , 'L' (left) i.e. (x - 1, y), 'R' (right) i.e. (x + 1, y)-
// Note:
// Here, sorted paths mean that the expected output should be in alphabetical order.

#include <iostream>
#include <vector>

using namespace std;

bool isSafe(int newx, int newy, vector<vector<bool>> &visited, vector<vector<int>> &arr, int n)
{
    if ((newx >= 0 && newx < n) && (newy >= 0 && newy < n) &&
        (visited[newx][newy] != 1) && (arr[newx][newy] == 1)) // if newx and newy are within the maze and not visited and not blocked
    {
        return true;
    }
    else
    {
        return false;
    }
}

void solve(int x, int y, vector<vector<int>> &arr, int n, vector<string> &ans, vector<vector<bool>> &visited, string path)
{

    // base case
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }

    // 4 movement
    // D,L,R,U

    // Down
    if (isSafe(x + 1, y, visited, arr, n))
    {
        visited[x][y] = 1;
        solve(x + 1, y, arr, n, ans, visited, path + "D");
        visited[x][y] = 0;
    }
    // Left
    if (isSafe(x, y - 1, visited, arr, n))
    {
        visited[x][y] = 1;
        solve(x, y - 1, arr, n, ans, visited, path + "L");
        visited[x][y] = 0;
    }
    // Right
    if (isSafe(x, y + 1, visited, arr, n))
    {
        visited[x][y] = 1;
        solve(x, y + 1, arr, n, ans, visited, path + "R");
        visited[x][y] = 0;
    }
    // Up
    if (isSafe(x - 1, y, visited, arr, n))
    {
        visited[x][y] = 1;
        solve(x - 1, y, arr, n, ans, visited, path + "U");
        visited[x][y] = 0;
    }
}

vector<string> searchMaze(vector<vector<int>> &arr, int n)
{
    // vector<vector<int>> twoD ={ {1, 0, 0, 0},
    //                             {1, 1, 0, 1},
    //                             {0, 1, 0, 0},
    //                             {1, 1, 1, 1}};

    vector<string> ans;
    vector<vector<bool>> visited(n, vector<bool>(n, 0)); // 2D vector of size n*n initialized with 0
    string path = "";

    solve(0, 0, arr, n, ans, visited, path);
}