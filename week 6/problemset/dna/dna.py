import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py DATABASEFILE SEQUENCEFILE")
        sys.exit(1)

    # TODO: Read database file into a variable
    # 1.Open file
    try:
        database_file = open(sys.argv[1], "r")
    except FileNotFoundError:
        print("File not Found!")
        sys.exit(1)

    # 2.Write database file to variable
    database_list = []
    database = csv.DictReader(database_file)
    for line in database:

        # Convert STRs value to an integer
        for value in line:
            try:
                line[value] = int(line[value])

            except ValueError:
                continue

        # Write each line into list
        database_list.append(line)

    # Write key to New Variable

    # Close database file
    database_file.close()

    # TODO: Read DNA sequence file into a variable
    try:
        sequence_file = open(sys.argv[2], "r")
    except FileNotFoundError:
        print("File not Found!")
        sys.exit(1)

    sequences = csv.reader(sequence_file)
    for i in sequences:
        sequence = i[0]

    # TODO: Find longest match of each STR in DNA sequence
    subsequences = {}
    for key in list(line.keys()):
        n = 0
        n = longest_match(sequence, key)
        subsequences[key] = n
    del subsequences['name']

    # TODO: Check database for matching profiles
    match = len(subsequences)

    # Loop for each person STRs
    for data in database_list:
        tracker = 0

        # Loop for STRs each person have, if match the sequences, add tracker 1
        for key in subsequences:
            if data[key] == subsequences[key]:
                tracker += 1

        # if tracker == match, mean all STRs in sequences match person STRs, print person name and exit
        if tracker == match:
            print(data['name'])
            sys.exit(0)

    # If no person STRs match subsequences, then:
    print("No match")
    sys.exit(1)
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
