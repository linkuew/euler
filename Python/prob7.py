# Finding prime numbers is usually quite difficult, and since so much
# of modern security relies on this fact, it's good that it's true for
# large numbers.  Thankfully, however, for (relatively) small numbers
# the process can be expedited thanks to Eratosthenes. I'm not sure
# if his wildest dreams could capture what the following code does,
# but at least his smallest dreams can capture the main idea.

# As a hint before the solution - we know that 2 is a prime, but then
# every number that is a multiple of 2 - 2*t where t is a natural number,
# is not a prime number.  Thus, if we construct an array of numbers such
# that we mark off every multiple of every prime, we can quickly construct
# an array of all prime numbers.

import numpy as np
ln = 200000

def main():
    nums = np.zeros(ln, np.int64)
    sieve(nums)
    j = 0
    for i in range(2, ln):
       if (nums[i] == 0):
           j += 1
       if (j == 10001):
           break

    print("The 10,001st prime is " + str(i))
    return 0

def sieve(nums):
    for i in range(2, ln):
        if (nums[i] == 0):
            for j in range(i, ln - i, i):
                nums[j + i] = 1

main()
