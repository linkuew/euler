# Similar to problem 7, we need to find prime numbers, and those
# can sometimes be tricky to locate.  However, using another
# sieve of Eratosthenes, this process can be expedited versus
# checking each individual number to see if it is prime.

# A lot (most) of this code is taken from prob7.py, check out
# that problem if you're having trouble understanding what's\
# going on here!

import numpy as np
ln = 2000000

def main():
    nums = np.zeros(ln, np.int32)
    sieve(nums)
    sum = 2
    for i in range(3, ln, 2):
        if (nums[i] == 0):
            sum += i
    print(sum)

def sieve(nums):
    for i in range(2, ln):
        if (nums[i] == 0):
            for j in range(i, ln - i, i):
                nums[j + i] = 1

main()
