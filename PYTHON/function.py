  
import math

ls = [1,2,3,4,5]
print ("The length of ls is :" ,len(ls))
data = int (input("enter number to sqrt"))
print ("the square of {} is {}.".format(data, math.sqrt(data)))

print ("The value of pi is:" ,math.pi)


data2 = int (input("Enter the number to be exponented"))
print ("The exponent of {} is {}.".format (data2, math.exp(data2)))

data3 = int (input("enter the number to be hex:"))
print ("The hexadecimal of {} is {}.".format(data3, hex(data3)))

def myFun():
    print("This is myFun")

print(myFun())

def add(a,b):
    return a+b

print (add(2, 3))