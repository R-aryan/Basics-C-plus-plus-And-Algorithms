'''
Given an array of integers, and a number ‘sum’, 
find the number of pairs of integers in the array whose sum is equal to ‘sum’.

Example- Input  :  arr[] = {1, 5, 7, -1}, 
          sum = 6
          Output :  2
          Pairs with sum 6 are (1, 5) and (7, -1)

'''

def pair_sum(arr,k):

    if len(arr)<=2:
        return
    
    #set for tracking
    seen=set()
    Output=set()

    for num in arr:
        target=k-num

        if target not in seen:
            seen.add(num)
        
        else:
            Output.add( (min(num,target),max(num,target)))
    
    print('\n'.join(map(str,list(Output))))

    return len(Output)


#call the function for output

pair= pair_sum([1,7,5,-1],6)
print(pair)