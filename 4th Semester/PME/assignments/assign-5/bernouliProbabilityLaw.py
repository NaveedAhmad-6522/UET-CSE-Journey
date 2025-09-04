"""
The Bernoulli probability law, also known as the Bernoulli distribution, is a discrete probability
distribution that models a single experiment with two possible outcomes: success or failure. It is
named after the Swiss mathematician Jacob Bernoulli.
The formula for the Bernoulli distribution is as follows: P(X = x) = p^x * (1 - p)^(1 - x)
"""

"""
 Let X be the number 0 (failure) if tails occur and 1 (success) 
if heads occur in a toss of a fair coin. Find the pmf of X. 
(Bernoulli RV)
"""
def bernoulliProbability(p, x):
    if not 0 <= p <= 1:
        raise ValueError("p must be within the range [0, 1].")

    if x != 0 and x != 1:
        raise ValueError("x must be a valid Bernoulli trial outcome (0 or 1).")

    if x == 0:
        return 1 - p
    else:
        return p

p = 0.4
head = 1
tail = 0

result = bernoulliProbability(p, head)
print(f"The probability of getting head:{head} in a Bernoulli trial with p={p} is: {result}")
print(f"The probability of getting tail:{tail} in a Bernoulli trial with p={p} is: {1- result}")
