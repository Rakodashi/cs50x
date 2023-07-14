from cs50 import get_float

# Gets how much change will be used to give out the propper number of coins
while True:
    money = get_float("Change for: ")
    if money >= 0:
        break

# Calculates the number of coins to give back according to types of cents
cents = int((money * 100) + 0.5)

totalCoins = 0
for coins in [25, 10, 5, 1]:
    totalCoins += cents // coins
    cents %= coins

print(totalCoins)