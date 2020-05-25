'''
Problem - Given two strings s1 and s2, check if both the strings are anagrams of each other.
An anagram of a string is another string that contains same characters, 
only the order of characters can be different. 
For example, “abcd” and “dabc” are anagram of each other.

'''

from collections import Counter

def check_anagram(first_string,second_string):
    d1=Counter(first_string)

    d2= Counter(second_string)

    # print(d1)
    # print(d2)

    if d1==d2:
        #print('Are anagrams')
        return True
    
    else:
        return False




s1= input("Enter first string \n")
s2= input("Enter second string \n")

if check_anagram(s1,s2):
    print('True')

else:
    print('False')