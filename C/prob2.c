/*
 * This problem has an easily found brute force solution
 * by checking whether a digit is even or odd. There is,
 * most likely, a more elegant mathematical solution for
 * this problem, but, sometimes, a mere solution is good
 * enough for the task at hand
 */
#include<stdio.h>

int fib(int i, int j);

int main(void)
{
        int f_0 = 1;
        int f_1 = 2;
        int f_n;
        int sum = 0;

        while (fib(f_0,f_1) < 4000000) {
                if (!(f_0 % 2)) {
                        sum += f_0;
                }
                f_n = f_1;
                f_1 = fib(f_0,f_1);
                f_0 = f_n;
        }

        if (!(f_1 % 2)) {
                sum += f_1;
        }

        printf("%d\n", sum);

        return 0;
}

int fib(int i, int j)
{
        return i + j;
}
