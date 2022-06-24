# This is more of a brute force method than I thought I would end up with
# but there is some fun finding of prime numbers by realizing a triangle
# number can always be expressed as the product of two smaller numbers.
# Finding the primes from these numbers is the most inefficient part,
# and it could be improved with a seive (of Eratosthenes or Atkin).

from collections import Counter

def main():
    tri_num = 1
    i = 1
    while (True):
        dims = get_square_dim(tri_num, i)
        primes = get_primes(dims)
        multiples = mult(primes)

        if (multiples > 500):
            print(tri_num)
            print(dims)
            print(primes)
            print(multiples)
            break

        tri_num += i + 1
        i += 1

    return 0


def get_square_dim(tri_num, i):
    dim1 = 0
    dim2 = 0

    if ((i + 1) % 2) == 0:
        dim1 = i
        dim2 = int((i + 1) / 2)
    else:
        dim1 = i + 1
        dim2 = int(i / 2)

    return [dim1, dim2]

def get_primes(dims):
    primes = []

    for dim in dims:
        i = 2
        while (i < (dim + 1)):
            if dim % i == 0 and is_prime(i):
                primes.append(i)
                dim = int(dim / i)
                i = 2
                continue
            if dim == 1:
                break
            i += 1

    return primes

def is_prime(num):
    if num % 2 == 0 and not num == 2:
        return False

    for i in range(3, num, 2):
        if num % i == 0:
            return False

    return True

def mult(primes):
    total = 1

    for val in Counter(primes).values():
        total *= (val + 1)

    return total


if __name__ == '__main__':
    main()
