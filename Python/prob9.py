# Finding the solution to this problem can be done by iteration
# and subsequently checking each a and b (and by extension c) to
# see if they are a 1) Pythagorean triple and 2) that they sum to
# 1000.  However, using a little algebra we can find the solution
# without looking through numerous possibilities.

# Begin by taking the second equation given, subtract a and b, then
# square both sides.  Then you'll have c^2 = (1000 - a - b)^2.  Plugging
# this into the Pythagorean equation, we can come up with a formula
# for a and b which can then be used to find integer solutions (using a
# CAS like Wolfram Alpha, like I subsequently did)

# This will result in a few possibilities, of which the true solution can
# be seen - try it for yourself!

def main():
    a = 200
    b = 375
    c = 1000 - (a + b)
    print(a*b*c)

main()
