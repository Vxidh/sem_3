print("Hello Warudo")

a, b = 10, "your mom" #We can define multiple variables in the same line this way

a = 1+2+3+ \
    4+5+6+ \
    7+8+9 #The \ character allows me to separate lines while declaring variables.


#range(a,b,x) --> starts from a, ends at b-1, increments with a value of x
#a, a+x, a+2x.... b-1
for i in range(3, 6, 1):
    print(i)
#This for loop will work from 3 to 5 and increment itself with a value of 1 everytime.

#Defining a function
def sum(a,b):
    print(a+b)

#Calling the function
sum(3,4)

#If the same function were to return instead of print, we can access the value by assigning it to a variable.

#LISTS
a=[]
for i in range(0,25,2):
    a[i] +=i #We are inserting values into the list by directly assigning values to its indices.

a.append(69) #We can also add elements to the end by using the append() function

