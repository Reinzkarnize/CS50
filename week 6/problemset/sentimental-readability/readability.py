from cs50 import get_string


def main():
    # Ask user for the input text
    word = get_string("Text: ")

    grade = count_readibility(word)

    # print Grade result
    if grade < 1:
        print("Before Grade 1")
    elif grade < 16:
        print(f"Grade {grade}")
    else:
        print("Grade 16+")


# Counting crade using Coleman-Liau index
def count_readibility(word):
    letter = 0
    sentence = 0
    words = 1

    # Count how many, letters, words and sentences
    for i in word:
        if i.isalpha():
            letter += 1
        elif i in ['!', '?', '.']:
            sentence += 1
        elif i == ' ':
            words += 1

    # Input count result to Coleman-Liau index
    L = letter / words * 100
    S = sentence / words * 100

    index = 0.0588 * L - 0.296 * S - 15.8
    grade = round(index)

    return grade


main()