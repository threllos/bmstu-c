import random
import sys
n = int(sys.argv[1])
print(n)
for i in range(n):
    print(random.randint(1, 100), end=" ")