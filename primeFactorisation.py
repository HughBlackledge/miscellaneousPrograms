import numpy as np


def isPrime(n):
    isNPrime = True
    for i in range(2, int(np.ceil(np.sqrt(n))+1)):
        if(n % i == 0):
            isNPrime = False
    return isNPrime

'''
for i in range(3, 100):
    print(str(i) + " " + str(isPrime(i)))
'''
def PrimeFactorisation(n):
    while(n > 1):
        i = 2
        while(i < int(np.ceil(np.sqrt(n))+1)):
            if(n % i == 0):
                print(i)
                n /= i
            i += 1


PrimeFactorisation(100)
