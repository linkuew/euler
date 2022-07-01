import math

a = int(math.pow(2,1000))
total = 0
for i in range(len(str(a))):
    total += int(str(a)[i])
print(total)

a = math.factorial(100)
total = 0

for i in range(len(str(a))):
    total += int(str(a)[i])

print(total)
