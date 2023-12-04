puts "Enter the file path:"

file_path = gets.chomp

file = File.open(file_path, "r")
file_data = file.read

puts "File data:"
puts file_data

for i in 0..5
    file_data.gsub! "  ", " "
end

file_data = file_data.split("\n")

total_sum = 0

for i in 0..file_data.length - 1
    puts file_data[i]

    card_content = file_data[i].split(" | ")
    good_card_part = card_content[0]
    test_card_part = card_content[1]
    good_card_numbers_str = good_card_part.split(": ")[1]
    good_card_numbers = good_card_numbers_str.split(" ")

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

    card_score = 0
    for j in 0..test_card_numbers.length - 1
        if good_card_numbers.include? test_card_numbers[j]
            if card_score == 0
                card_score = 1
            else
                card_score = card_score * 2
            end
        end
    end
    puts "Card score: #{card_score}"
    total_sum = total_sum + card_score
end

puts "Total sum: #{total_sum}"
