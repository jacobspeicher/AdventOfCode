f = open('input_2.txt')
words = []
for line in f:
    words.append(line[:-1])

found = False
i = 0
while(not found):
    words_dict = {}
    for w in words:
        if i < len(w):
            if i == len(w):
                mod_w = w[:i]
            else:
                mod_w = w[:i] + w[i+1:]
            # print(mod_w, w)
            if words_dict.get(mod_w) is None:
                words_dict[mod_w] = 1
            else:
                words_dict[mod_w] += 1
    for k in words_dict:
        if words_dict[k] > 1:
            print(k)
            found = True
    i += 1