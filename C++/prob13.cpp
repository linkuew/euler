/**
 * For this problem, we'll ignore the finer details of the
 * theoretical solutions that involve some cool imagination,
 * for instance, the max sum of 50 digits is 450 - so what can
 * we say about all carries for the program?
 *
 * C++ does not have native support for arbitrarily length numbers,
 * but there are a few libraries that support such operations, one is
 * GNU Multiple Precision Arithmetic Library (GMP) found at (for right now)
 * https://gmplib.org/
 *
 * Props to the maintainers of the GMP library, this ran much faster than I
 * expected
 */
#include<iostream>
#include<fstream>
#include<string>
#include<gmp.h>

using namespace std;
int main(void) {
        // not a confusing name at all
        string num;
        fstream file;

        try {
                file.open("large_sum.txt",ios::in);
        } catch (...) {
                cout << "Error opening file\n";
                return 1;
        }

        // initialize the variables we'll be using for the prog
        mpz_t sum, tmp;
        mpz_init(sum);
        mpz_init(tmp);

        // find the sum
        while (getline(file, num)) {
                mpz_set_str(tmp, num.c_str(), 10);
                mpz_add(sum, sum, tmp);
        }

        gmp_printf("The sum is: %Zd\n", sum);

        // freeing memory is cool
        file.close();
        mpz_clear(sum);
        mpz_clear(tmp);

        return 0;
}
