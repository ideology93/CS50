from cs50 import get_string
## global variables

ae1 = 34
ae2 = 37
mc1 = 51
mc2 = 52
mc3 = 53
mc4 = 54
mc5 = 55
card = ''

# main method


def main():
    getInput()
    check()

# gets user input


def getInput():
    global card
    while(True):
        userInput = get_string("Enter your credit card number: \n")
        if userInput.isdigit():  # checks if the input is digits
            card = userInput
            break

# algorhytm that provides check info


def luhn():
    global card
    totalB = 0
    totalA = 0
    dig = len(card)-2
    reg = len(card)-1
    for i in card:
        #  calculates digit sum going second to last backwards
        if dig >= 0:
            cc = int(card[dig])*2
            sumDig = sum(int(digit) for digit in str(cc))   # sums the digits if there's more than 2 in a number
            dig -= 2
            totalB = int(sumDig) + totalB
        if reg >= 0:
            totalA = int(card[reg]) + totalA
            reg -= 2
    result = (totalA+totalB) % 10
    return result

# method that checks the validity of the card


def check():
    digs = str(card[0])+str(card[1])
    firstDigits = int(digs)
    test = luhn()
    if(test == 0):
        if(len(card) == 13 or len(card) == 15 or len(card) == 16):  # only possible number of digits in cards
            if(int(card[0]) == 4):
                print("VISA")
            elif(firstDigits == mc1 or firstDigits == mc2 or firstDigits == mc3 or firstDigits == mc4 or firstDigits == mc5):
                print("MASTERCARD")
            elif(firstDigits == ae1 or firstDigits == ae2):
                print("AMEX")
            else:
                print("INVALID")
        else:
            print("INVALID")
    else:
        print("INVALID")


main()

