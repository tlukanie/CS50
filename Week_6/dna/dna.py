import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    # TODO: Read database file into a variable
    people_db = list()
    if (sys.argv[1] == "databases/small.csv"):
        with open(sys.argv[1]) as file:
            reader = csv.DictReader(file)
            for line in reader:
                line["AGATC"] = int(line["AGATC"])
                line["AATG"] = int(line["AATG"])
                line["TATC"] = int(line["TATC"])
                people_db.append(line)
    #    print(people_db)
    else:
         # print("BIG")
         with open(sys.argv[1]) as file:
            reader = csv.DictReader(file)
            for line in reader:
                line["AGATC"] = int(line["AGATC"])
                line["TTTTTTCT"] = int(line["TTTTTTCT"])
                line["AATG"] = int(line["AATG"])
                line["TATC"] = int(line["TATC"])
                line["TCTAG"] = int(line["TCTAG"])
                line["GATA"] = int(line["GATA"])
                line["GAAA"] = int(line["GAAA"])
                line["TCTG"] = int(line["TCTG"])
                people_db.append(line)
    # TODO: Read DNA sequence file into a variable
    with open(sys.argv[2], 'r') as file_txt:
        # rstrip() method removes any trailing characters
        dna_sequence = file_txt.read().rstrip()
    # print(dna_sequence)

    # TODO: Find longest match of each STR in DNA sequence
    agatc_longest = longest_match(dna_sequence, "AGATC")
    # print(agatc_longest)
    aatg_longest = longest_match(dna_sequence, "AATG")
    # print(aatg_longest)
    tatc_longest = longest_match(dna_sequence, "TATC")
    # print(tatc_longest)
    ttt_longest = longest_match(dna_sequence, "TTTTTTCT")
    tctag_longest = longest_match(dna_sequence, "TCTAG")
    gata_longest = longest_match(dna_sequence, "GATA")
    gaa_longest = longest_match(dna_sequence, "GAAA")
    tctg_longest = longest_match(dna_sequence, "TCTG")


    # TODO: Check database for matching profiles
    # print(len(people_db))
    match = "No"
    if (sys.argv[1] == "databases/small.csv"):
        for i in range(len(people_db)):
                    if (people_db[i]["AGATC"] == agatc_longest and people_db[i]["AATG"] == aatg_longest and people_db[i]["TATC"] == tatc_longest):
                     #print(people_db[i]["name"])
                        match = people_db[i]["name"]
                        break
                    if (match == "No"):
                        match = "No match"
    else:
        for i in range(len(people_db)):
                    if (people_db[i]["AGATC"] == agatc_longest and people_db[i]["AATG"] == aatg_longest and
                        people_db[i]["TATC"] == tatc_longest and people_db[i]["TTTTTTCT"] == ttt_longest and
                        tctag_longest == people_db[i]["TCTAG"] and gata_longest == people_db[i]["GATA"] and
                        gaa_longest == people_db[i]["GAAA"] and tctg_longest == people_db[i]["TCTG"]):
                     #print(people_db[i]["name"])
                            match = people_db[i]["name"]
                            break
                    if (match == "No"):
                        match = "No match"
    print(match)

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
