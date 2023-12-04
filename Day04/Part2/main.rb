# Get the file path from the user
puts "Enter the file path:"

file_path = gets.chomp

file = File.open(file_path, "r")
file_data = file.read

# Print the file data
puts "File data:"
puts file_data

# Remove the extra spaces to split the data easily
for i in 0..5
    file_data.gsub! "  ", " "
end

# Split the data into lines
file_data = file_data.split("\n")

# Initialize the dupplicates array (defines how many cards have the same number)
dupplicates = [1] * (file_data.length + 20)

total_sum = 0

# Compute each card score
for i in 0..file_data.length - 1
    # Print the card data
    puts file_data[i]

    # Split the card data into good card numbers and test card numbers
    card_content = file_data[i].split(" | ")

    good_card_part = card_content[0]
    test_card_part = card_content[1]

    # Split the good card numbers and test card numbers into arrays
    good_card_numbers_str = good_card_part.split(": ")[1]
    good_card_numbers = good_card_numbers_str.split(" ")

    # Split the good card numbers and test card numbers into arrays
    for j in 0..good_card_numbers.length - 1
        good_card_numbers[j] = good_card_numbers[j].to_i
    end
    test_card_numbers = test_card_part.split(" ")

    for j in 0..test_card_numbers.length - 1
        test_card_numbers[j] = test_card_numbers[j].to_i
    end

    # Compute the card score
    card_score = 0
    for j in 0..test_card_numbers.length - 1
        # Apply the score rules(just check how many numbers match the good card numbers)
        if good_card_numbers.include? test_card_numbers[j]
            card_score = card_score + 1
        end
    end

    # Update the dupplicates array (Copies cards if needed)
    for j in 1..card_score
        dupplicates[i + j] = dupplicates[i + j] + dupplicates[i]
    end

    # Add the current card copies to the total sum
    total_sum = total_sum + dupplicates[i]
end

# Print the total sum
puts "Total sum: #{total_sum}"
