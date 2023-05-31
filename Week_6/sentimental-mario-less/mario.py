from cs50 import get_int
# TODO
while True:
    height = get_int("Height: ")
    if (height > 0 and height < 9):
        break
i = 0
while (i < height):
    j = -1
    k = i
    while (k < height - 1):
        print(" ", end='')
        k += 1
    while (j < i):
        print("#", end='')
        j += 1
    print("\n", end='')
    i += 1
