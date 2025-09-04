"""
A fair coin is flipped 3 times and the number of heads X is 
noted. VAR[X] of X
"""
def factorial(n):   # n! = n * (n - 1) * (n - 2) * ... * 2 * 1
    if(n < 0):
        return - 1;
    if(n <= 1):
        return 1
    return n * factorial(n - 1)

def combinationOf(n, k):    # nCk = n!/(k! * (n-k)!)
    if(n < 0 or k < 0):
        return - 1
    if(n < k):
        return -1
    nFact = factorial(n)
    kFact = factorial(k)
    difFact = factorial(n - k)

    return nFact / (kFact * difFact)

def binomialLaw(totalTrials, nthTrial, success):
    c = combinationOf(totalTrials , nthTrial)
    p = success
    q = 1 - success

    return float( c * p**nthTrial * q**(totalTrials-nthTrial))

tosses = 3
p = 0.5

variance = 0
e2X = 0
eX2 = 0
for k in range(0, tosses+1):
    prob = binomialLaw(tosses, k, p)
    print(f"P[X = {k}] = {prob}")
    eX2 += k**2 * prob
    e2X += k * prob
print(f"Variance V[X] = {eX2 - e2X**2}")