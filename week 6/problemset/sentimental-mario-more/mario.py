from cs50 import get_int

# Ask user for height betwen 1 to 8
while True:
    height = get_int("Height: ")
    if height > 0 and height < 9:
        break

# print Block
block = 1
space = height - 1
for i in range(height):
    print(" " * space + "#" * block + "  " + "#" * block)
    block += 1
    space -= 1