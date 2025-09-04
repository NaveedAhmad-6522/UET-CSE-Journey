import random
chars="azxcvbnmmtrkert4u923tyeg]f1geufwhw"

password=""
lenght=int(input("enter lenght"))
for i in range(lenght):
    password+=random.choice(chars)

print(password)