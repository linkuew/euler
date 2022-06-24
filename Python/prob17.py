# Wrote this to see how quickly I could do it! I am happy to admit that
# I solved this on the first try - I don't recommend this method, but it works!
# this problem is a little easier for me, but I can't imagine if this problem was
# posed in French, as the Canadians and the French would probably come up with
# different solutions once we reach 80.

ONES = ['', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine']
TENS = ['', 'ten', 'twenty', 'thirty', 'forty', 'fifty', 'sixty', 'seventy', 'eighty', 'ninety']
TEENS = ['', 'eleven', 'twelve', 'thirteen', 'fourteen', 'fifteen', 'sixteen', 'seventeen', 'eighteen', 'nineteen']
HUNDS = 'hundred'
THOU = 'thousand'

from math import log

total = 0

for i in range(1, 1001):
    if log(i, 1000) >= 1:
        total += len(ONES[(i + 1) % 1000]) + len(THOU)
    elif log(i, 100) >= 1:
        if 11 <= i % 100 <= 19:
            total += len(ONES[int(i / 100)]) \
                    + len(HUNDS) \
                    + len('and') \
                    + len(TEENS[i % 10])
        elif not i % 100 == 0:
            total += len(ONES[int(i / 100)]) \
                    + len(HUNDS) \
                    + len('and') \
                    + len(TENS[int((i % 100) / 10)]) \
                    + len(ONES[i % 10])
        else:
            total += len(ONES[int(i / 100)]) \
                    + len(HUNDS)
    elif log(i, 10) >= 1:
        if 11 <= i % 100 <= 19:
            total += len(TEENS[i % 10])
        elif not i % 100 == 0:
            total += len(TENS[int((i % 100) / 10)]) \
                    + len(ONES[i % 10])
        else:
            total += len(ONES[int(i / 100)]) \
                    + len(HUNDS)
    else:
        total += len(ONES[i])


print(total)
