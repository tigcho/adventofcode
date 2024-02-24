with open('input.txt') as f:
    data = f.read()

position = 0
count = 0

for char in data:
    position += 1
    count += 1 if char == '(' else -1 if char == ')' else 0

print('Santa is on floor', count)
