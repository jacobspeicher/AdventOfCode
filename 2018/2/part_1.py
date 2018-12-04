f = open('input_2.txt')
threes = 0
twos = 0
for i in f:
    letters = {}
    is_three = False
    is_two = False
    for char in i:
        if not letters.has_key(char):
            letters[char] = 0
        letters[char] += 1
    for k in letters:
        if letters[k] == 3:
            is_three = True
        if letters[k] == 2:
            is_two = True
    if is_three:
        threes += 1
    if is_two:
        twos += 1
checksum = threes * twos
print(checksum)
