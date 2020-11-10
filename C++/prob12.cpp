/**
 * Herein we find a problem whose solution can be linked to a later problem:
 * by using Pascal's triangle (like in problem 15), we can find all the
 * triangular numbers using factorials to expedite the process
 *
 * In addition, we need only find prime divisors (and then sum all
 * combinations of said primes to find the true number of divisors)
 */

#include<iostream>
#include<limits>
#include<math.h>

using namespace std;

int divisors(unsigned long long tri, int *primes, int *unique);
void sieve(int *primes);
int choosing(int N);
int choose(int N, int k);


int main(void)
{
        unsigned long long tri = 1;
        int *primes = (int *) calloc(1000, sizeof(int));
        sieve(primes);
        int n;
        int unique = 0;

        for (unsigned int i = 2; i <= numeric_limits<unsigned int>::max(); i++) {
                // gives the total number of non-distinct primes
                n = divisors(tri, primes, &unique);
                /*
                cout << "At triangle number " << tri <<
                        " there are " << n << " prime divisors" <<
                        " and " << unique << " **unique** prime divisors\n";//"for a total of" <<
                        //1 + n + choosing(n) << "\n";
                */
                for (int j = 0; j < 1000; j++) {
                        cout << primes[j] << " ";
                }
                cout << "\n";
                /*
                if ((1 + unique + choosing(n)) > 500) {
                        cout << "Triangle number " << tri << " has over 500 divisors\n";
                        break;
                }
                */

                tri += i;
                unique = 0;
        }

        free(primes);
        return 0;
}

int divisors(unsigned long long tri, int *primes, int *unique)
{
        int count = 0;
        int i = 0;
        int same = 0;
        *unique = 0;

        while (tri != 1 && i != 1000) {
                if (tri % primes[i] == 0) {
                        tri /= primes[i];
                        count++;
                        if (same == 0) {
                                *unique += 1;
                                same = 1;
                        }
                } else {
                        i++;
                        same = 0;
                }
        }

        return count;
}

void sieve(int *primes)
{
        int len = 7920;
        char *indices = (char *) calloc(len, sizeof(char));

        for (int i = 2; i <= len; i++) {
                if (indices[i] == 0) {
                        for (int j = i; j <= len - i; j += i) {
                                indices[j+i] = 1;
                        }
                }
        }

        int j = 0;
        for (int i = 2; i <= len; i++) {
                if (indices[i] == 0) {
                        primes[j] = i;
                        j++;
                }
        }

        free(indices);
}

int choosing(int N)
{
        int total = 0;
        for (int j = 2; j <= N; j++) {
                total += choose(N, j);
        }
        return total;
}

// calculate N choose k
int choose(int N, int k)
{
        int total = 1;
        for (int i = 1; i <= k; i++)
                total *= (N - (k - i)) / i;
        return total;
}
