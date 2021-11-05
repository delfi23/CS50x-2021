import sys
import csv


def main():
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py DATABASE SEQUENCE")

    # List containing the data base information
    dataBase = []
    dnaSeq = []

    with open(sys.argv[1]) as dataFile:
        reader = csv.reader(dataFile)
        # Save each row in dataBase including row 0 where are the definitions of the type of data in csv (name,STR1,STR2,etc)
        for row in reader:
            dataBase.append(row)

    # Read the .txt sequence sample file into a string
    with open(sys.argv[2]) as f:
        dnaSeq = f.read()       # (name of file)f.read()

    # Save the amount of repeatitions for each STR founded in the sequence in a list
    repetitions_STR = []
    
    for i in range(1, len(dataBase[0])):
        STR = dataBase[0][i]
        repetitions_STR.append(countSTR(dnaSeq, STR))

    # Compare the repetitions extracted from the sample sequence with the ones of each person given in data base
    person_STR = []
    personData = []
    notFound = 1
    
    for i in range(1, len(dataBase)):
        personData = dataBase[i]
        # Save in an array/list the amount of repetitions of the person for each STR
        person_STR = getPersonSTR(personData)
        if (person_STR == repetitions_STR):
            print(dataBase[i][0])
            notFound = 0
            break
    if (notFound):
        print("No match")


# Counts the repetitions of the STR and returns the maximum
def countSTR(dnaSeq, STR):
    count = maxCount = i = 0
    
    while i < len(dnaSeq):
        j = i + len(STR)
        s = dnaSeq[i:j]
        if (STR == s):
            i = j
            count += 1
        else:
            i += 1
            if (count > maxCount):
                maxCount = count
            count = 0

    return maxCount


# Get the person STR information and return it as an array to compare with the one from the sequence
def getPersonSTR(personData):
    
    person = []
    j = 1
    while j < len(personData):
        person.append(int(personData[j]))
        j += 1
    return person


main()

