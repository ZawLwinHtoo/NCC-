db={}


def main_sector():
    main_option = int(input("Press 1 to register.\nPress 2 to login.\nPress 3 to exit."))
    if main_option == 1:
        registration()
    elif main_option == 2:
        log_in()
    elif main_option == 3:
        exit(1)
    else:
        print("Invalid option!\n")
        main_sector()

def registration():
    print("This is registration section:")
    r_email=input("Enter your email:")
    get_email = email_exit_checking(r_email)
    if get_email!= None:
        print("Email already exit. Please try again!\n")
        registration()
    else:

        r_password = input("Enter your password:")
        id = len(db)

        to_insert = {id: {"email": r_email, "password": r_password}}
        db.update(to_insert)

def log_in():
    user_found = -1
    print("This is log in\n")
    l_email = input ("Enter your email to log in:")
    l_password = input ("Enter your password:")
    for i in range (len(db)):
        if l_email == db[i]["email"] and l_password == db[i]["password"]:
            user_found = i

    if user_found != -1:
        print("Log in succeed")
        user_profile(l_email)
    else:
        print("Log in failed!")


def user_profile(info):
    print("Welcome:",info)

def email_exit_checking(email):
    for i in range(len(db)):
        if db[i]["email"] == email :
            return i

if __name__ == '__main__':
    while True:
        main_sector()