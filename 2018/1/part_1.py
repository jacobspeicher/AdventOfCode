f = open("input_1.txt")
freq = 0
for i in f:
    mod = i[0]
    if mod == '+':
        freq += int(i[1:])
    else:
        freq -= int(i[1:])
print(freq)
