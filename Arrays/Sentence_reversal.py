'''
Given a string of words. Reverse all the words Also remove all the trailing white spaces

Example-

Input- This is the best

Output- best the is This

'''

def reverse_sentence(sentence):
    '''
    sentence- a string of words
    example- this is best
    '''

    sentence= sentence.strip()

    l1= sentence.split(' ')
    #print(l1)
    s=" "

    for word in l1:
        s=word+" "+s

    return s.strip()



res=reverse_sentence("this is the best   ")
print(res)