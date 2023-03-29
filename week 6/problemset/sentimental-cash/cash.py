from cs50 import get_float


def main():
    # Ask how many cents the customer is owed
    cents = get_cents()

    # Calculate the number of quarters to give the customer
    quarters = calculate_quarters(cents)
    cents = round(cents - quarters * 0.25, 2)

    # Calculate the number of dimes to give the customer
    dimes = calculate_dimes(cents)
    cents = round(cents - dimes * 0.1, 2)

    # Calculate the number of nickels to give the customer
    nickels = calculate_nickels(cents)
    cents = round(cents - nickels * 0.05, 2)

    # Calculate the number of pennies to give the customer
    pennies = calculate_pennies(cents)
    cents = round(cents - pennies * 0.01, 2)

    coins = quarters + dimes + nickels + pennies

    # Print total number of coins to give the customer
    print(coins)


# Ask user for change owed, must be  > 0
def get_cents():
    while True:
        cents = get_float("Change owed: ")
        if cents > 0:
            return cents


# Subtract to quarter when cents in >= quarter value
def calculate_quarters(cents):
    counter = 0
    while cents >= 0.25:
        cents = round(cents - 0.25, 2)
        counter += 1
    return counter


# Subtract to dime when cents in >= dime value
def calculate_dimes(cents):
    counter = 0
    while cents >= 0.1:
        cents = round(cents - 0.1, 2)
        counter += 1
    return counter


# Subtract to nickle when cents in >= nickle value
def calculate_nickels(cents):
    counter = 0
    while cents >= 0.05:
        cents = round(cents - 0.05, 2)
        counter += 1

    return counter


# Subtract to penny when cents in >= penny value
def calculate_pennies(cents):
    counter = 0
    while cents >= 0.01:
        cents = round(cents - 0.01, 2)
        counter += 1

    return counter


main()