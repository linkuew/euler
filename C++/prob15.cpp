/**
 * For this problem, we could try and find some closed form solution
 * to the problem, but that might take a little longer than noting that
 * for the 3x3 grid given as an example, we can find the number of paths
 * by first starting with the origin, seeing that there is one way to get
 * to either the point immediately right or immediately below, then note
 * that the sum of these possible paths is the number of ways to get to
 * the "diagonal down" point (either going right-down or down-right).
 * This general principle extends to an arbitrary NxM grid with only two
 * orthogonal valid moves.  So, we simply construct a 21x21 matrix, and
 * fill each slot with the number of possible moves to that point
 *
 * However, you might consider another simple solution - since we
 * must have 20 rights and 20 downs in grid, we must first find
 * all the combinations of the rights and downs and then remove
 * all the repeats of rights and downs...
 */
#include<iostream>
#include<math.h>

using namespace std;

int main(void)
{
        int size = 21;
        unsigned long long grid[size][size];

        // initialize edges
        for (int i = 0; i < size; i++) {
                grid[0][i] = 1;
                grid[i][0] = 1;
        }

        // fill in the rest of the matrix
        for (int i = 1; i < size; i++) {
                for (int j = 1; j < size; j++) {
                        grid[i][j] = grid[i-1][j] + grid[i][j-1];
                }
        }

        cout << "Total number of paths is " << grid[size-1][size-1] << "\n";

        // perhaps easier i suppose
        cout << "It is also " << tgamma(40) / tgamma(20) / tgamma(20) << "\n";

        return 0;
}
