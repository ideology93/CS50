from cs50 import get_int, get_string

while (True):
    number = get_int("Height:\n")
    if number in range(1, 9):
        space = number-1
        hashtag = 1
        for i in range(number):  # double for loop
            separator = ' ' * space
            print(separator, end='')  # spacing
            space -= 1
            for j in range(hashtag):
                print("#", end='')
            hashtag += 1
            print()  # new row
        exit()