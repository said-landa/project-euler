#Largest Palindrome Product

#A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 * 99.
#Find the largest palindrome made from the product of two 3-digit numbers.


from math import ceil

num1 = 999
num2 = 998
lim = 899

prefixes = range(997, 99, -1) #start at 997 because mirroring 998 gives 998899, which is already above the largest possible product, 999 × 999 = 998001.
palindromes = (int(str(prefix) + str(prefix)[::-1]) for prefix in prefixes) #Builds each palindrome when the loop asks for it. For 997, str(prefix) gives "997", and [::-1] reverses it to "799". Joining them and converting back to an integer gives 997799.
for palindrome in palindromes: #Takes one candidate at a time. The first two are 997799 and 996699.
    lowerBound = ceil(palindrome // 999) #what is the lower bound to start testing? if the palindrome at hand is 997799, its two possible three-digit factors 'a' and 'b' must be <= than 999 --given the statement of the problem--, so we have the inequality: lowerBound * 999 >= 997799, or ceil(lowerBound = 997799 / 999)
    for factor in range(990, lowerBound - 1, -11): ##every palindrome is divisible by 11 (crazy), so at least one of its factors must be a multiple of 11. We start at 990, the largest 3-digit multiple of 11, and step down by 11 while we stat at >= lowerBound. For the first tested palindrome --997799-- the lowerBound is 999, which is greater than the maximum possible factor 990, so we skip it.
        if palindrome % factor == 0:
            print(f"{palindrome} = {factor} x  {palindrome // factor}")
            raise SystemExit

