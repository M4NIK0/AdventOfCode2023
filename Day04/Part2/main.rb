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

dupplicates = [1] * (file_data.length + 20)

total_sum = 0

for i in 0..file_data.length - 1
    puts file_data[i]

    card_content = file_data[i].split(" | ")
    good_card_part = card_content[0]
    test_card_part = card_content[1]
    good_card_numbers_str = good_card_part.split(": ")[1]
    good_card_numbers = good_card_numbers_str.split(" ")

    for j in 0..good_card_numbers.length - 1
        good_card_numbers[j] = good_card_numbers[j].to_i
    end

    test_card_numbers = test_card_part.split(" ")

    for j in 0..test_card_numbers.length - 1
        test_card_numbers[j] = test_card_numbers[j].to_i
    end

    card_score = 0
    for j in 0..test_card_numbers.length - 1
        if good_card_numbers.include? test_card_numbers[j]
            card_score = card_score + 1
        end
    end

    for j in 1..card_score
        dupplicates[i + j] = dupplicates[i + j] + dupplicates[i]
    end

    total_sum = total_sum + dupplicates[i]
end

puts "Total sum: #{total_sum}"
