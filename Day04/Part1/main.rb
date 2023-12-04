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
    puts "Good card numbers:"
    for j in 0..good_card_numbers.length - 1
        good_card_numbers[j] = good_card_numbers[j].to_i
        puts good_card_numbers[j]
    end
    test_card_numbers = test_card_part.split(" ")

    puts "Test card numbers:"
    for j in 0..test_card_numbers.length - 1
        test_card_numbers[j] = test_card_numbers[j].to_i
        puts test_card_numbers[j]
    end

    # Compute the card score
    card_score = 0
    for j in 0..test_card_numbers.length - 1
        # Check if the test card number is in the good card numbers
        if good_card_numbers.include? test_card_numbers[j]
            # Apply the score rules
            if card_score == 0
                card_score = 1
            else
                card_score = card_score * 2
            end
        end
    end
    # Print the card score
    puts "Card score: #{card_score}"

    # Add the card score to the total sum
    total_sum = total_sum + card_score
end

# Print the total sum
puts "Total sum: #{total_sum}"
