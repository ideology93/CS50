from sys import argv, exit
from os import path
import csv
import os
import sys
import string


# checks number of arguments
if (len(argv) != 3 or not(argv[1].endswith('.csv')) or not(argv[2].endswith('.txt'))):
    print("Invalid command-line arguments")
    exit(1)

# reads the DNA file with the path provided in argument and returns a string


def read_dna(dna_path):
    if os.path.isfile(dnaPath):
        with open(dnaPath) as dnaFile:
            readDna = dnaFile.read()
            return readDna


# reads the Database(csv) file and saves it in a dictionary
def read_database(db_path):
    dic = []
    reader = csv.DictReader(open(db_path))
    for line in reader:
        dic.append(dict(line))
    keys = reader.fieldnames
    keys.pop(0)
    return dic, keys


# looks for the 'STR' in the DNA string and its highest amount of consecutive repeats
def find_dna(keys, dna):
    response = {}
    for key in keys:
        pointer = 0
        response[key] = 0
        repeats = 0
        while(True):
            if dna[pointer:].startswith(key):
                pointer += len(key)
                repeats += 1
            else:
                pointer += 1
                repeats = 0
            if repeats > response[key]:
                response[key] = repeats
            if pointer >= len(dna) - len(key):
                break
    return response


# function to check matching dna in the database
def checkDNA(db_names, DNAresult):
    names = []
    for name in db_names:
        match = True
        for key in DNAresult.keys():
            if str(name[key]) != str(DNAresult[key]):
                match = False
                break
        if (match):
            names.append(name["name"])
    return names


# reminder, finish the STR search inside of the find methods
if __name__ == '__main__':
    # path to CSV file provided in arguments
    databasePath = argv[1]
    # path to dnk (txt) file provided in arguments
    dnaPath = argv[2]
    # print("DB path:", databasePath)
    # print("DNA path:", dnaPath)

    # reading the database
    # print("\nReading database......\n")
    # these lists contain they keys we're looking for and the database of people
    DBnames, keys = read_database(databasePath)
    if DBnames == None:
        print("Database doesn't exist!")
        exit(1)
    # print("Database elements:\n\n ", end="")
    # print(DBnames)
    # print("Keys: ", end="")
    # print(keys)

    # read the DNA
    # print("\n Reading DNA...... \n")
    # this list holds the dna we're supposed to check
    dna = read_dna(dnaPath)
    if dna == "":
        print("DNA doesn't exist")
        exit(1)
    # print("DNA: ", end="")
    # print(dna)

    # find DNA
    # print("\nLooking for DNA")
    DNAresult = find_dna(keys, dna)
    # print("DNA Results : ", end="")
    # print(DNAresult)

    # check the DNA
    # print("\n Checking the DNA....")
    match = checkDNA(DBnames, DNAresult)
    # print("Matched people: ", end="")
    if (match == []):
        print("No match")
        exit(1)
    print(match[0])
