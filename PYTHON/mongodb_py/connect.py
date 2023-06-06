import pymongo
import random
connection = pymongo.MongoClient("localhost", 27017)
database = connection["nccdip2"]
collection = database["user_info"]


if __name__ == '__main__':
    while True:
        try:
            u_id:int = random.randint(1,100)
            u_email:str = str(input("Enter your email:"))
            u_pw:str = str(input("Enter your password:"))
            u_ph:int = int(input("Enter ph no:"))

            data_form = {"_id": u_id, "email": u_email, "password": u_pw, "phone": u_ph}
            ids = collection.insert_one(data_form)
            print("Inserted id:",ids.inserted_id)
        except Exception as err:
            print(err)
