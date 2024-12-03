#!/bin/bash

# Function to check if a list of numbers is sorted
is_sorted() {
    local prev=$1
    shift
    for num in "$@"; do
        if (( $(echo "$num < $prev" | bc -l) )); then
            return 1
        fi
        prev=$num
    done
    return 0
}

# # Generate random numbers
numbers=$(shuf -i 1-100000 -n 100 | tr "\n" " ")
# echo "Generated numbers: $numbers"

# # Run PmergeMe and capture its output
output=$(./PmergeMe $numbers)
# echo "PmergeMe output: $output"

# Extract the sorted numbers from the output
# Assuming the output is just the sorted numbers
sorted_numbers=$(echo "$output" | tr -s ' ' '\n' | tr '\n' ' ' | sed 's/[[:space:]]*$//')
# echo "Extracted sorted numbers: $sorted_numbers"

# Check if the output is sorted
if is_sorted $sorted_numbers; then
    echo "The output is correctly sorted."
else
    echo "Error: The output is not correctly sorted."
    exit 1
fi

# Compare the input and output
input_set=$(echo $numbers | tr -s ' ' '\n' | sort -n | uniq)
output_set=$(echo $sorted_numbers | tr -s ' ' '\n' | sort -n | uniq)

# Debugging: Print input and output sets
# echo "Input set: $input_set"
# echo "Output set: $output_set"

# Ensure both input and output sets are non-empty
if [ -z "$input_set" ] || [ -z "$output_set" ]; then
    echo "Error: One of the sets is empty."
    exit 1
fi

echo "Input set size: $(echo "$input_set" | wc -l)"
echo "Output set size: $(echo "$output_set" | wc -l)"

if [ "$input_set" = "$output_set" ]; then
    echo "The output contains the same numbers as the input."
else
    echo "Error: The output does not match the input."
    echo "Numbers in input but not in output:"
    comm -23 <(echo "$input_set") <(echo "$output_set")
    echo "Numbers in output but not in input:"
    comm -13 <(echo "$input_set") <(echo "$output_set")
    exit 1
fi

echo "All checks passed successfully!"