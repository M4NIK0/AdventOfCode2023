# Gets first digit from a given string, returned as int
def get_first_digit(string:str) -> int:
    """Returns the first digit of a string"""
    # Starts loop in the string
    for i in string:
        # Check if current character is a digit
        if i.isdigit():
            # Returns digit as int
            return int(i)

# Gets last digit from a given string, returned as int
def get_last_digit(string:str) -> int:
    """Returns the last digit of a string"""
    # Starts loop at end of the string, going in reverse order
    for i in string[::-1]:
        # Check if current character is a digit
        if i.isdigit():
            # Returns digit as int
            return int(i)

# List of all retreived numbers
list_of_numbers = []

# Sum of all retreived numbers
final_number = 0

# Open needed input file
with open(input("Tell me the absolute path: ")) as f:
    # Reads and format lines as needed
    data = f.read().splitlines()
    for i in data:
        # Adds found numbers from a given line with this formula
        # (first_digit * 10) + last_digit
        # if first_digit = 7 and last_digit = 9:
        # (7 * 10) + 9 = 70 + 9 = 79
        list_of_numbers.append((get_first_digit(i) * 10) + get_last_digit(i))

    # Adds up all given numbers
    for i in list_of_numbers:
        final_number += i
    
    # Print final number to give on the website
    print("FINAL NUMBER:", final_number)
