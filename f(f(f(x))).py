def f(x): return x - ((x+1)%3) + ((x-1)%3)

print("The Equation: ","x - ((x+1)%3) + ((x-1)%3)")
for x in range(1,100):
    print(x,"=",f(f(f(x))))
