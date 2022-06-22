# Since these are triangle numbers, we'll take Gauss' childhood
# techniques for this problem, thereby finding the two middle divisors.
# From these two middle divisors, we use prime factorization to find their
# respective divisors, then construct a list to keep track of their repsective
# divisors

def main():
    # iterate through the triangle numbers
    tri_num = 1
    i = 1
    while (True):
        f_dict = find_primes(tri_num, i)
        m_dict = multiples(f_dict)

        print(m_dict)
        print(tri_num)
        print()

        if i > 10:
            break
        tri_num += i + 1
        i += 1

def find_primes(tri_num, i):
    dim1 = 0
    dim2 = 0

    if ((i + 1) % 2) == 0:
        dim1 = i
        dim2 = int((i + 1) / 2)
    else:
        dim1 = i + 1
        dim2 = int(i / 2)

    print('dims = ' + str(dim1) + ',' + str(dim2))

    return factors(dim1, dim2)

def factors(dim1, dim2):
    nums = {}

    if (dim1 % 2) == 0 or (dim2 % 2) == 0:
        nums[2] = 1

    for i in range(1, dim1 + 1):
        if (dim1 % i) == 0:
            nums[i] = 1

    for i in range(1, dim2 + 1):
        if (dim2 % i) == 0:
            nums[i] = 1

    return nums

def multiples(nums):
    tmp_list = []
    for base in nums.items():
        for tmp in nums.items():
            if base[0] == tmp[0]:
                continue
            tmp_list.append(base[0] * tmp[0])

    for item in tmp_list:
        nums[item] = 1

    return nums


if __name__ == '__main__':
    main()
