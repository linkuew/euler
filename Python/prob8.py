# Unfortunately, this is not a very good solution - if I were
# searching over a larger number for combinations, this method
# would not work - however, for this problem it is good enough,
# although I might come back and update it to use mean instead
# of sum - just using the sum yielded some problems, perhaps
# you can see why that would be!

# Finding this solution can take some time, but will not require
# comparisons of numbers. Instead, a scoring system can be used
# to find out the greatest product of thirteen digits.  All this
# requires is an adequate scoring system

# Note that since multiplication is commutative, we do not care
# about the order.  That is 123 and 231 both have products of 6.
# Therefore, all we care about are the following two facts -
# 1) the sum of all the digits will closest to the greatest, and
# 2) there must not be a 0 present in the grouping of 13 digits.
# The second property yields a shortcut we can take in our
# programming - instead of checking every combination of 13 digits,
# we can skip over those that have at least one 0 present.
num = 731671765313306249192251196744265747423553491949349698352031277450632623957831801698480186947885184385861560789112949495459501737958331952853208805511125406987471585238630507156932909632952274430435576689664895044524452316173185640309871112172238311622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450

def main():
    # Place number into an string
    ints = [int(i) for i in str(num)]
    new_score = 0
    prod = 1
    tmp2 = 1
    # Find combinations of 13 numbers - should
    # be shortened
    for i in range(0, len(ints)):
        tmp = score(ints, i)
        if (tmp > new_score):
            new_score = tmp
            tmp2 = 1
            for j in range(i, i + 13):
                tmp2 *= ints[j]
            if (tmp2 > prod):
                prod = tmp2
    print(prod)


def score(ints, i):
    tmp = 0
    for j in range(i, i+13):
        if (ints[j] == 0):
            return 0
        tmp += ints[j]
    return tmp

main()
