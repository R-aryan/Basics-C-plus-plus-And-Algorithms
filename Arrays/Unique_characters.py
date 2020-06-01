'''
To implement an algorithm to determine if a string contains all unique characters.

Examples:
Input : s = “abcd”
Output: True
“abcd” doesn’t contain any duplicates. Hence the output is True.
'''
def check_unique_characters(sen):
    '''
    sen = an string example- "aabbdcf"
    '''
    chars=set()
    for i in sen:
        if i in chars:
            return False
        else:
            chars.add(i)
    
    return True

r=check_unique_characters("aabbcdee")

if r:
    print("All characters are unique")

else:
    print("Duplicate character present")