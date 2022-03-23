#include <iostream>
#include <vector>


/*********************************************************
Approach #1 DFS [Accepted]
Intuition
Treat the 2d grid map as an undirected graph and there is an edge between two horizontally or vertically adjacent nodes of value '1'.
Algorithm
Linear scan the 2d grid map, if a node contains a '1', 
then it is a root node that triggers a Depth First Search. 
During DFS, every visited node should be set as '0' to mark as visited node. 
Count the number of root nodes that trigger DFS, this number would be the number of islands since each DFS starting at some root identifies an island.
**********************************************************/

using namespace std;

class SolutionNoOfIsland {
public:
    int numIslands(vector<vector<char>>& grid) {

        if(grid.size() == 0)
            return 0;
        int nr = grid.size();
        int nc = grid[0].size();

        int numOfI = 0;
        for(int r = 0; r < nr; ++r)
            for(int c = 0; c < nc; ++c)
                if(grid[r][c] == '1')
                    numOfI += dfs(grid, r, c);
        
		return numOfI;
    }

    int dfs(vector<vector<char>>& grid, int r, int c)
    {
        int nr = grid.size();
        int nc = grid[0].size();
        
		if(r < 0 || r >= nr || c < 0 || c >= nc || grid[r][c] == '0')
            return 0;

        grid[r][c] = '0';
        
		dfs(grid, r + 1, c);
        dfs(grid, r - 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r, c - 1);

        return 1;
    }
};

/*
int main()
{
	vector<vector<char>> grid = {
								 {'1','1','0','0','0'},
								 {'1','1','0','0','0'},
								 {'0','0','1','0','0'},
								 {'0','0','0','1','1'}
								};
	cout << SolutionNoOfIsland().numIslands(grid);
	return 0;
}
*/
