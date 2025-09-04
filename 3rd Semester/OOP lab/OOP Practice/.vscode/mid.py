import random
num=random.randint(1,6)
guess=None
while guess!=num:
    number=int(input("enter number"))
    if guess==num:
    print("cong")
    else:
    print("you guess correct")
