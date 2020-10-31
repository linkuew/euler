# Solving this problem could involve looping, but thankfully there is a
# nice, closed form solution for this problem using Gauss' childhood
# revelations

size = 100
square_sum = ((size / 2) * (size + 1))**2
sum_o_squares = (size * (size+1) * (2*size+1)) / 6

print(square_sum - sum_o_squares)
