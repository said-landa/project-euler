num1 = 999
num2 = 998
lim = 899

def arePalin(num):
    return str(num) == str(num)[::-1]
    
prefixes = range(997, 99, -1)
done = False

while num1 > lim and not done:
    while num2 > lim:
        prod = num1 * num2
        if(arePalin(prod)):
            done = True
            print(f"Biggest palindrome is {prod}")
            break
        else: 
            num2 -= 1
    if (num1 == lim + 1):
        lim = lim - 100
    num1 -= 1  
    num2 = num1 - 1   