from cs50 import get_string

# Get text sample
sample = get_string("Text: ")

letters = sents = words = 0

# Checks if it contains properly separated, non-symbol words
for ch in sample:
    if ch.isalpha():
        letters += 1
    if ch.isspace():
        words += 1
    if ch in ["?", ".", "!"]:
        sents += 1
words += 1

# Calculates each of the formula variables
L = (letters * 100.0) / words
S = (sents * 100.0) / words
formula = round(0.0588 * L - 0.296 * S - 15.8)

# Prints out the sample text Grade
if formula < 1:
    print("Before Grade 1")
elif formula >= 16:
    print("Grade 16+")
else:
    print(f"Grade {formula}")