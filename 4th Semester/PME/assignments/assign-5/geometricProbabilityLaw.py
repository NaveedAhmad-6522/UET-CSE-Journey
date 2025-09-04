"""
The geometric probability distribution is often used to model the number of trials needed until the
first success in a sequence of independent Bernoulli trials, where each trial has the same probability of
success, denoted by 'p'.
The probability mass function (PMF) of the geometric distribution is given by the formula: 
P(X = k) = (1 - p)^(k - 1) * p

where:
X is the random variable representing the number of trials until the first success.
k is the number of trials needed until the first success.
p is the probability of success in each trial.

"""

def geometricLaw(nthTrial, success):
    failure = 1 - success
    return (failure ** (nthTrial - 1)) * (success)

print("Geometric Probability:")

n = int(input("Enter total n? "))
p = float(input("Enter Success Probability? "))

for k in range(1, n+1):
    print(f"P[X = {k}] = {geometricLaw(k, p)}")