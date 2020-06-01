'''
Given an input string, write a function that returns the Run Length Encoded string for the input string.

For example, 
if the input string is ‘wwwwaaadexxxxxx’, 
then the function should return ‘w4a3d1e1x6’.

'''

def encode_string(sentence):
    '''
    sentence- a string pf any length example- wwwwaaadexxxxxx
    '''

    count_freq={}
    s=''
    
    for i in sentence:

        if len(sentence)==0:
            return None


        if i not in count_freq.keys():
            count_freq[i]=1
        
        else:
            count_freq[i]+=1
        
    for k,v in count_freq.items():
        
        s= s+ str(k)+ str(v)
    
    return s


res=encode_string("wwwwaaadexxxxxx") 
print(res)