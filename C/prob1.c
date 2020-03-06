/*
 * This problem involves a simple choice between mathematical
 * formulation versus brute force - this method presents the
 * simple brute force method, but if you would like to find
 * a "faster" method, I would encourage looking at the formula
 * 1+2+...+n = (n/2)(n+1), and then considering how you would
 * adapt this formula for multiples of 5, if you would like a
 * hint, look to the end of this code
 */

#include<stdio.h>

int main(void)
{
        int i = 0;
        int sum = 0;

        for (i = 0; i < 1000; i++) {
                if (!(i % 3)) {
                        sum += i;
                } else if (!(i % 5)) {
                        sum += i;
                }
        }

        printf("%d\n", sum);

        return 0;
}

/*
 * Hint - every number n that is a multiple of 5 can
 * be expressed as 5t, where t is in Z_+
 */

