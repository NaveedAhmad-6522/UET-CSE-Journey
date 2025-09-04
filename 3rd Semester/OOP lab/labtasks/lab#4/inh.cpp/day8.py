import random
guess=None
num=random.randint(1,6)
exit_flage=False
while guess !=num:
    input_user=int(input("enter a number 1,5 "))
    if input_user==guess:
        print("you won the game")
        break
    else:
        print("Try again")
