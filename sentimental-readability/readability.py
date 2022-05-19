from cs50 import get_string


def main():
    check()


def getInput():  # just gets user input
    userInput = get_string("Text: \n")
    return userInput


def check():  # checks for validity
    nonletter = 0  # all variables needed for this
    spaces = 0
    dashes = 0
    letters = 0
    words = 1
    sentences = 0
    text = getInput()
    for c in text:
        if (c == ',' or c == '\'' or c == '\"' or c == ':' or c == ';'):
            nonletter += 1
        elif(c == ' '):
            spaces += 1
            words += 1
        elif(c == '-'):
            dashes += 1
        elif(c == '!' or c == '?' or c == '.'):
            sentences += 1
        else:
            letters += 1
    L = float((letters/words) * 100)
    S = float((sentences/words) * 100)
    index = 0.0588 * L - 0.296 * S - 15.8
    grade = round(index)
    if (grade > 16):
        print("Grade 16+\n")  # writes grade
    elif (grade < 1):
        print("Before Grade 1\n")  # writes grade
    else:
        print(f"Grade {grade}\n")  # writes grade


main()  # runs