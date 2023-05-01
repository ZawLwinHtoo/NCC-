import pickle

db={}

global email_exit
email_exit=-1

def main_sector():
    main_option =int(input("Press 1 to Register:\nPress 2 to Login\nPress 3 Exit:"))
    if main_option== 1:
        registration()
    elif main_option==2:
        login()
    elif main_option==3:
        exit(1)
    else:
        print("Invalid Option")
        main_sector()

def registration():

    user_email = input("Enter your email:")
    email_get = Email_exit(user_email)

    if email_get!=None:
        print("Email already exit:")
        registration()
    else:
        user_name = input("Enter your username:")
        user_password = input("Enter your password:")
        user_phone = int(input("Enter your phone:"))
        user_age = int(input("Enter your age:"))

        id = len(db)

        to_insert = {id: {"email": user_email,"u_name":user_name, "password": user_password,"phone":user_phone,"age":user_age}}
        db.update(to_insert)


def login():
    user_found=-1;
    print("This is login sector")
    l_user_email = input("Enter your email to login:")
    l_user_password = input("Enter your password to login:")


    for i in range(len(db)):
        if db[i]["email"] == l_user_email and db[i]["password"]==l_user_password:

            user_found=i
    if user_found!=-1:
        print("Login Success!")
        user_profile(user_found)
    else:
        print("Not Found ")

def user_profile(user_found):
    print("Welcome:",db[user_found]["u_name"])

    input("Press 1 ")


def Email_exit(email):

    lenght = len(db)
    for i in range(lenght):
        if db[i]["email"] == email:
            return i


def recording_all_data_to_file():

    with open("file.txt", 'w') as fptr:
        # for key, value in db.items():
        #     fptr.write('%s:%s\n' %(key,value))
        fptr.write(str(db))
        fptr.write('\n')

def loading_all_data_to_file():
    with open("file.txt",'r') as fptr:
        i = (fptr.read())
        db.update(eval(i))
        # data = fptr.read()
        # print(type(data))
        # dd = bytes(data,'utf-8')
        # print(type(dd))
        # d = pickle.loads(dd)
        # print(type(d))



# def loading_all_data_to_file():
#
#     with open ("file.txt",'r')as fptr:

if __name__ == '__main__':

   while True:
       loading_all_data_to_file()
       main_sector()
       recording_all_data_to_file()


