# Conditional Probability: P(A|B) = P(A and B) / P(B) 

'''
Example: Consider rolling a fair six-sided die. Suppose we want to find the probability
of rolling an even number (A) given that the roll resulted in a number less than or
equal to 4 (B)
'''

def findConditionalProbability(event_A, event_B, sampleSpace):
    lenSS = len(sampleSpace)
    len_A = len(event_A)
    len_B = len(event_B)

    AandB = event_A.intersection(event_B)    # A n B
    lanAandB = len(AandB)

    probOfAandB = lanAandB / lenSS   # P[A n B]
    probOfEvent_B = len_B / lenSS #P[B]

    prob = probOfAandB / probOfEvent_B   
    return prob


sampleSpace = {1,2,3,4,5,6} #Die

A = set((2,4,6))    # even outcomes
B = set((1,2,3,4))  # outcomes <= 4

p = findConditionalProbability(A, B, sampleSpace)
print(f"The Probability of A|B. P[A|B] = {p}")