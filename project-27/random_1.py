import random

# Generate a 100-digit number
number = ''.join(random.choices('0123456789', k=100))

# Count the number of repetitions for each digit
digit_counts = [number.count(str(digit)) for digit in range(10)]

# Print the results
print(number)
for digit, count in enumerate(digit_counts):
    print(f"Digit {digit} appears {count} times in the generated number.")
