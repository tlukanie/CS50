# TODO
from cs50 import get_float


def get_cents():
    while True:
        i = get_float("Change owed: ")
        if (i > 0):
            break
    coin = int(i * 100)
    # print(coin)
    return coin


def calculate_quarters(cents):
    if (cents >= 25):
        result = cents / 25
    else:
        result = 0
    return int(result)


def calculate_dimes(cents):
    if (cents >= 10):
        result = cents / 10
    else:
        result = 0
    return int(result)


def calculate_nickels(cents):
    if (cents >= 5):
        result = cents / 5
    else:
        result = 0
    return int(result)


def calculate_pennies(cents):
    if (cents >= 1):
        result = cents / 1
    else:
        result = 0
    return int(result)


cents = get_cents()
# print(cents)

quarters = calculate_quarters(cents)
cents = cents - quarters * 25
# print(quarters)
# print(cents)

dimes = calculate_dimes(cents)
cents = cents - dimes * 10

nickels = calculate_nickels(cents)
cents = cents - nickels * 5

pennies = calculate_pennies(cents)
cents = cents - pennies * 1

coins = quarters + dimes + nickels + pennies
print(coins)