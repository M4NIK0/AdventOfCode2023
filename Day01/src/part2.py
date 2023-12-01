# Gets first digit from a given string, returned as int
def get_first_digit(string:str) -> int:
    """
    Returns the first digit of a string
    It can be a number or the spelled number
    one = 1 for example
    """
    # Dictionnary of spelled numbers to ints
    numbers_spelled = {
        "zero": 0,
        "one": 1,
        "two": 2,
        "three": 3,
        "four": 4,
        "five": 5,
        "six" : 6,
        "seven": 7,
        "eight": 8,
        "nine": 9,
    }

    # Loop in the string
    for i in range(len(string)):
        # Check if current character is a digit
        if (string[i].isdigit()):
            # Returns digit as int
            return int(string[i])
        # Loop to check if current place is a spelled digit
        for j in numbers_spelled:
            # Check if current character corresponds
            if (string[i] == j[0]):
                # Loop in spelled character
                for k in range(len(j)):
                    # If a character is not the same as the spelled one, breaks the chain
                    if (string[i + k] != j[k]):
                        break
                    # If everything went good, returns the digit using the dictionnary
                    if (k == len(j) - 1):
                        return numbers_spelled[j]

# Gets last digit from a given string, returned as int
def get_last_digit(string:str) -> int:
    """
    Same as previous function but it returns the last digit
    """
    # Dictionnary of spelled numbers to ints
    numbers_spelled = {
        "zero": 0,
        "one": 1,
        "two": 2,
        "three": 3,
        "four": 4,
        "five": 5,
        "six" : 6,
        "seven": 7,
        "eight": 8,
        "nine": 9,
    }

    # Loop in the string in reverse order
    for i in range(len(string), 0, -1):
        # Check if current character is a digit
        if (string[i - 1].isdigit()):
            # Returns digit as int
            return int(string[i - 1])
        # Loop to check if current place is a spelled digit
        for j in numbers_spelled:
            # Check if current character corresponds
            if (string[i - 1] == j[-1]):
                # Loop in spelled character
                for k in range(len(j)):
                    # If a character is not the same as the spelled one, breaks the chain
                    if (string[i - 1 - k] != j[-1 - k]):
                        break
                    # If everything went good and we ended the spelled string without any error
                    if (k == len(j) - 1):
                        # Returns the digit using the dictionnary
                        return numbers_spelled[j]


list_of_numbers = []
final_number = 0

with open(input("Tell me the absolute path: ")) as f:
    data = f.read().splitlines()
    for i in data:
        list_of_numbers.append((get_first_digit(i) * 10) + get_last_digit(i))
        print(list_of_numbers[-1])

    for i in list_of_numbers:
        final_number += i
    
    print("FINAL NUMBER:", final_number)
