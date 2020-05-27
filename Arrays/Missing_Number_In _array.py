'''
Given two arrays which are duplicates of each other(but the elements in the second array is shuffled)
except one element, that is one element from one of the array is missing,
we need to find that missing element.

example-Input: arr1[] = {2, 3, 4, 5}
               arr2[] = {2, 3, 4, 5, 6}
Output: 6
6 is missing from first array

'''

def find_missing_number(arr1,arr2):
    result=0
    '''
    arr1- list of integers
    arr2- second list of integers
    arr1+arr2- this operation performs the concetanation of the array 
    not the sum of elements
    '''

    for num in arr1+arr2:
        #taking XOR of the elements of the list
        result^=num

    return result

r=find_missing_number([2,3,4,5],[3,4,5,2,6])

print(r)