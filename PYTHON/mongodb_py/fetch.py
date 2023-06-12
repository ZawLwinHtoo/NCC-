import pymongo

connector = pymongo.MongoClient("localhost", 27017)
database = connector["nccdip2"]
collection = database["user_info"]

l_email = input("Enter your email:")

for i in collection.find({},{"_id":0,"email":1}):
    if l_email == i["email"]:
        print("Welcome",i["email"])
    else:
        print("Email not found")
