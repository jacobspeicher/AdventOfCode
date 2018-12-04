freqs = { 0: 1 }
cur_freq = 0
found = False
while(not found):
    f = open('input_1.txt')
    for i in f:
        mod = i[0]
        if mod == '+':
            cur_freq += int(i[1:])
            if freqs.has_key(cur_freq):
                found = True
                break
            else:
                freqs[cur_freq] = 1
        if mod == '-':
            cur_freq -= int(i[1:])
            if freqs.has_key(cur_freq):
                found = True
                break
            else:
                freqs[cur_freq] = 1
print(cur_freq)
