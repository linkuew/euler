/*
 * At certain times, we find a tidbit of useful information tucked away, ready
 * to be used at the proper time. This is just that, and I promise
 * that you will *not* understand this code. This was bourne out of a book,
 * read years ago. And if you wish to understand this code, you must first
 * file through the pages of that book. Secrets of Mental Math.
 */

#include <stdio.h>

int main(void)
{
        int month_code;
        int year_code;

        int i;
        int j;

        int sundays = 0;

        int mon[] = {0, 6, 2, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
        int leap_mon[] = {0, 5, 1, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};

        for (i = 1; i <= 100; i++) {
                year_code = i + (i / 4);

                for (j = 1; j <= 12; j++) {
                        if (i % 4 == 0) {
                                month_code = leap_mon[j];
                        } else {
                                month_code = mon[j];
                        }

                        if ((year_code + month_code + 2) % 7 == 0) {
                                sundays = sundays + 1;
                        }
                }
        }
        printf("# of Sundays: %d\n", sundays);

        return 0;
}
