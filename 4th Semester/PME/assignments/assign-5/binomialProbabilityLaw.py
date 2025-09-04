'''
The Binomial Probability Law is a probability distribution that describes the number
of successes in a fixed number of independent Bernoulli trials. It is applicable when
there are only two possible outcomes for each trial (e.g., success or failure),
and the trials are independent and have the same probability of success.

The formula for the Binomial Probability Law is as follows:
P(X = k) = C(n, k) * p^k * (1 - p)^(n - k)
'''
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

print("Binomial Probability:")

n = int(input("Enter total n? "))
p = float(input("Enter Success Probability? "))

for k in range(0, n+1):
    print(f"P[X = {k}] = {binomialLaw(n, k, p)}")