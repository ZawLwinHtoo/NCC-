# string = "hello world"
# print (string.upper())
# print(string.lower())
# print(string.isupper())
# print(string.islower())
# S = string.upper()
# print(S.isupper())
# print(string.count('hell'))
# print("index is:",string.find("w"))
# new = string.replace("hello", "mfs")
# print(new)

a= 60
b = 13
c=10    #0000 1010

# print(a&b)
# print(a|b)
# print(c>>1) #0000 0101
# print(c<<2) #0010 1000

d=60
print(a is not b)
print(a is d)
print(a is b)

aa="hello"
bb ="hello"

print( id(aa),'\n',id(bb))
if aa is bb:
    print("Same memory address")

if "lll" in aa:
    print("exist")
else:
    print("err")