/**
 * There are a few different ways to approach the problem,
 * I found it easiest to imagine the sample space and then
 * decrease it slowly.  The resulting code explores through
 * approximately 1,000,000 possibilities, using some logical
 * deductions about the nature of the solution. While not
 * a closed form solution - the ideas I came up with involved
 * solving a system of nonlinear equations with 6 unknowns -
 * the code should run smoothly without using much memory
 *
 * Some helpful hints - I start from a solution (that is, a palindrome)
 * and then try and find the two numbers.  Why does this help?  Rather
 * than searching through all possible multiplications from 100-999,
 * the process can be expedited by first looking at palindromes, because
 * the set of palindromes is smaller than the set of pairs of three digit
 * numbers.
 *
 * Next, I start my search from the largest palindromes to the smallest,
 * given the nature of the problem, we can assume that the palindrome
 * will be reasonably large - large enough that we'll probably have to
 * search more than half the sample space if we start from the bottom.
 *
 * Looking back at the program I wrote - it seems fairly long and
 * complicated for the task at hand. Multiplying numbers and checking
 * to see if the result was a palindrome probably would have been easier,
 * but I think thinking about the solution space was a good exercise
 */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int six(char *num);
int five(char *num);
int multiples(int n);

int main(void)
{
        char *num = malloc(6 * sizeof(char));
        for(int i = 0; i < 6; i++)
                num[i] = '9';

        if (six(num) || five(num))
                printf("The largest palindrome is %s\n", num);

        free(num);
        return 0;
}

int six(char *num)
{
        int i;
        int j;
        int k;
        for(i = 9; i >= 1; i--) {
                num[0] = num[5] = (char) (i + 48);
                for (j = 9; j >= 0; j--) {
                        num[1] = num[4] = (j + 48);
                        for (k = 9; k >=0; k--) {
                                num[2] = num[3] = (k + 48);
                                if (multiples(atoi(num))) {
                                        printf("%s\n", num);
                                }
                        }
                }
        }

        return 0;
}

int five(char *num)
{
        char *nnum = num + 1;
        int i;
        int j;
        int k;
        for(i = 9; i >= 1; i--) {
                nnum[0] = num[4] = (char) (i + 47);
                for (j = 9; j >= 0; j--) {
                        nnum[1] = num[3] = (char) (j + 47);
                        for (k = 9; k >=0; k--) {
                                num[2] = (char) (k + 47);
                                if (multiples(atoi(nnum))) {
                                        return 1;
                                }
                        }
                }
        }

        return 0;
}

int multiples(int n)
{
        int i;
        for (i = 999; i >= 100; i--) {
                if (!(n % i)  && ((int) log10(n / i)) == 2) {
                        printf("The two three digit numbers are %d and %d\n",
                                i, n / i);
                        return 1;
                }
        }
        return 0;
}
