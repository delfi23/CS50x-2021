from cs50 import get_float

while True:
    change = get_float("Change owed: ")
    if (change > 0):
        break

cents = round(change * 100)
q = int(cents / 25)                              # q is the amount of quarter coins needed
d = int((cents - q * 25) / 10)                   # d is for the dime coins
n = int((cents - q * 25 - d * 10) / 5)           # n for the nickels
p = int((cents - q * 25 - d * 10 - n * 5))       # p for the pennies needed

totalCoins = q + d + n + p

print(f"Coins: {totalCoins}")
