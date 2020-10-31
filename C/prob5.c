/**
 * A hint to think about the problem before rushing in and solving it:
 * All numbers are composed of smaller building blocks, and whenever
 * you require a number n to divisible by another number m, the building
 * blocks of m also divide n.
 *
 * A little analysis of the problem yields an easy method to solve.
 * First note that we can just construct said number from the total
 * number of unique prime factors such that every number from 1-20
 * can be represented.  That is, find a sequence of prime numbers
 * a_1, a_2,...,a_n such that for any number k in [1,20]
 * k = a_i*a_[i+1]*...*a_j, i <= j.
 */
#include<stdio.h>

int main(void)
{
        // This won't make much sense at first glance, but if you work
        // through the hint given above, you should find the why.
        int ans = 2 * 3 * 2 * 5 * 7 * 2 * 3 * 11 * 13 * 2 * 17 * 19;

        printf("%d is the smallest number divisible by all numbers 1-20\n", ans);
        return 0;
}
