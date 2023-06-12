import json

data_form = '{"id":0,"name":"zlh","pass":"apple"}'

myapi = json.loads(data_form)
print(myapi)
print(type(myapi))

str = json.dumps(myapi)
print(str)
print(type(str))