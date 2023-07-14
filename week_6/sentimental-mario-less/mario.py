from cs50 import get_int
# Gets height input and giver the conditional range of values which can be used.
while True:
    n = get_int("Pyramid Height: ")
    if n >= 1 and n <= 8:
        break

# Implements the pyramid height and rows according to the given parameters.
for row in range(1, n + 1):
    print(" " * (n - row) + "#" * row)