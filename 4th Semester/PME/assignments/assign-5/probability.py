import random

def tossCoin():
    result = random.random()

    if(result > 0.5):
        return "Heads"
    else:
        return "Tails"

def rollDice():
    return random.randint(1, 6)

def drawCard():
    suits = ["Hearts", "Diamonds", "Clubs", "Spades"]
    ranks = ["Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"]

    suit = random.choice(suits)
    rank = random.choice(ranks)

    return f"{rank} of {suit}"
    
for i in range(10):
    print(tossCoin())

for i in range(10):
    print(rollDice())
    
for i in range(10):
    print(drawCard())