from cs50 import get_float

change = 0
while(True):
    changeInput = get_float("How much change are you owed?\n")
    if changeInput >= 0:
        break
change = changeInput * 100  # turns change into cents
quarters = int(change / 25)  # finds how many quarters in change
remainQuarters = change % 25  # find the remainder of change
dimes = int(remainQuarters / 10)  # etc etc
remainDimes = remainQuarters % 10
nickels = int(remainDimes / 5)
remainNickels = remainDimes % 5
pennies = int(remainNickels / 1)
remainPennies = remainNickels / 1
totalCoins = quarters + dimes + nickels + pennies
print(f"{totalCoins}")
