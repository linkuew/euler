/**
 * Similar to the previous problems, brute
 * force methods would yield the correct
 * answer, but there are some things we can
 * note.  First, the number is odd, so 2 is obviously
 * not a prime factor.  Further, the sum of its digits
 * is not a multiple of 3, so we can cross of those numbers,
 * and then proceed to look for a number that is smaller
 * than n / i, where i is 2, 3, etc.
 *
 * The program, I realize now, displays all prime factors of
 * the number - but this is still faster than descending from
 * the "top" of the list (from the number itself downward).
 * If you'd like to think about why that is, don't look at the
 * next few lines yet.
 *
 * Since we know that 2 and 3 are not prime factors, we know
 * that the other prime factors *must* be located in the
 * first third of numbers leading up to the big one. That is,
 * |---xxxxxx| where --- is the set of possible multiples and
 * all of xxxxxx is not possible.  This set of --- keeps
 * getting smaller the more numbers we find that are *not* prime
 * factors.
 *
 * The method also doesn't check exclusively check prime numbers,
 * this could be accomplished with a sieve of Eratosthenes, but
 * given I didn't know exactly how large the largest prime was,
 * I decided to forgo this method for a decently fast, space
 * efficient algorithm.
 */

#include <stdio.h>
#include <stdlib.h>

#define const_num 600851475143

int main(void)
{
        unsigned long int num = const_num;
        unsigned long int i = 0;

        for (i = 7; i < const_num / i; i += 2) {
                if ((num % i) == 0) {
                        num = num / i;
                        printf("%lu\n", i);
                }
        }

        return 0;
}
