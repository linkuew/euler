/**
 * Starting off with a simple "try until we get
 * somewhere" method, starting with the largest
 * numbers to the smallest numbers
 */

#include<iostream>

using namespace std;

unsigned int length(unsigned int n);

int main(void)
{
        int max = 0;
        int index = 0;
        int tmp = 0;
        for (unsigned int i = 1000000; i > 0; i--) {
                tmp = length(i);
                if (tmp > max) {
                        max = tmp;
                        index = i;
                }
        }

        cout << "The longest chain is " << max << " found at "
                << index << "\n";

        return 0;
}

unsigned int length(unsigned int n)
{
        unsigned int len = 0;

        while (n != 1) {
                if (!(n % 2)) {
                        n = n / 2;
                } else {
                        n = 3*n + 1;
                }
                len++;
        }
        return len;
}
