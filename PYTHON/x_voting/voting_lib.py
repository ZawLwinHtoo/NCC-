class Voting:
    def __init__(self):
        print("This is special method also known as constructor:")
        self.db: dict = {}
        self.id: int = 0
        self.l_id: int = 0
        self.candidate: dict = {}
        # self.candidate: dict = {0: {"name": "James", "v_mark": 0, "voter": []},
        #                         1: {"name": "John", "v_mark": 0, "voter": []},
        #                         2: {"name": "Rooney", "v_mark": 0, "voter": []},
        #                         3: {"name": "Messi", "v_mark": 0, "voter": []},
        #                         4: {"name": "Ronaldo", "v_mark": 0, "voter": []}}

    def main_option(self):
        option = 0
        try:
            option = int(input("\nPress 1 to register.\nPress 2 to log in.\nPress 3 to exit."))
        except Exception as err:
            print("Error. Please enter integer only!!!", err)

        if option == 1:
            self.registration()
        elif option == 2:
            self.login()
        elif option == 3:
            exit(1)
        else:
            self.main_option()

    def registration(self):
        print("This is registration section")
        pass_match = False
        try:
            r_email = input("Enter your email to register:")
            r_name = input("Enter your name:")
            r_phone = int(input("Enter your phone number:"))
            r_add = input("Enter your address:")
            r_amount = int(input("Enter your amount"))
            while pass_match is False:
                r_pass1 = input("Enter your password:")
                r_pass2 = input("Retype your password:")

                if r_pass1 != r_pass2:
                    print("Your password was incorrect!!")

                else:
                    print("Your password is recorded.")
                    self.id: int = len(self.db)
                    total_data: dict = {
                        self.id: {"email": r_email, "name": r_name, "password": r_pass1, "phone": r_phone,
                                  "address": r_add, "amount": r_amount}}
                    self.db.update(total_data)
                    print(self.db)
                    break

        except Exception as err:
            print("Err while registration\n", err)
            self.registration()
        print("Registration succeed, Sir", self.db[self.id]["name"])
        self.recording_db_to_file()
        self.main_option()

    def login(self):
        print("THis is log in sector:")
        length = len(self.db)

        try:
            l_email = input("Enter your email to log in:")
            l_password = input("Enter your password:")
            self.l_id = -1
            for i in range(length):
                if self.db[i]["email"] == l_email and self.db[i]["password"] == l_password:
                    self.l_id = i
                    self.user_sector(self.l_id)
                    break

            print("User name or password incorrect:")
            self.login()
        except Exception as err:
            print(err, "Invalid input.")

    def user_sector(self, id):
        print("\nThis is user sector")
        print("Welcome, Sir", self.db[id]["name"], "\n")
        print("Select one!")
        j = 0
        for i in range(len(self.candidate)):
            print("id:{} - Name:{} - currentVote: {}".format(i, self.candidate[i]["name"], self.candidate[i]["v_mark"]))
            j = i
        try:
            v_id = int(input("Enter id number to vote:"))
            if v_id > j:
                print("Id out of bound. Please try again.")
            else:
                if self.db[id]["amount"]-500 >= 0:

                    self.candidate[v_id]["v_mark"] += 1
                    self.candidate[v_id]["voter"].append(self.db[id]["name"])
                    print("Congratulation, your voting have succeed!\n")
                    self.db[id]["amount"] -= 500
                    self.recording_db_to_file()
                    self.recording_candidate_to_file()
                    print("Candidate {}'s now voting mark is: {}".format(self.candidate[v_id]["name"],
                                                                         self.candidate[v_id]["v_mark"]))

                    for i in range(len(self.candidate[v_id]["voter"])):
                        print("Voter:", self.candidate[v_id]["voter"][i])
                else :
                    print("Insufficient amount. Please cash in more.")
        except Exception as err:
            print(err)

        while True:
            try:
                option = int(input("\nPress 1 to vote again.\nPress 2 to get back to main option.\nPress 3 to exit"))
                if option == 1:
                    self.user_sector(id)
                    break
                elif option == 2:
                    self.main_option()
                    break
                elif option == 3:
                    exit(1)
                else:
                    print("Invalid option. Please try again!")
            except Exception as err:
                print(err, "\nPlease enter the given option in integer only!")

    def recording_db_to_file(self):
        with open("file.txt", 'w') as fptr:
            for i in range(len(self.db)):
                Email = self.db[i]["email"]
                Name = self.db[i]["name"]
                pw = self.db[i]["password"]
                ph = self.db[i]["phone"]
                add = self.db[i]["address"]
                amount = self.db[i]["amount"]
                total_data = Email + ' ' + Name + ' ' + pw + ' ' + str(ph) + ' ' + add + ' ' + str(amount) + '\n'
                fptr.write(total_data)

    def loading_db_from_file(self):
        with open("file.txt", 'r') as fptr:
            per_line = fptr.readlines()

            for i in per_line:
                id = len(self.db)
                one_line = i.split(" ")
                data_form = {id: {"email": one_line[0], "name": one_line[1], "password": one_line[2],
                                  "phone": int(one_line[3]), "address": one_line[4], "amount": int(one_line[5])}}
                self.db.update(data_form)

    def recording_candidate_to_file(self):
        with open("file2.txt", 'w') as fptr:
            for i in range(len(self.candidate)):
                name = self.candidate[i]["name"]
                mark = self.candidate[i]["v_mark"]
                voter = ""
                for j in range(len(self.candidate[i]["voter"])):
                    if voter == "":
                        voter = voter + self.candidate[i]["voter"][j]
                    else:
                        voter = voter + "@" + self.candidate[i]["voter"][j]

                total_data = name + ' ' + str(mark) + ' @' + voter + '\n'
                fptr.write(total_data)

    def loading_candidate_from_file(self):
        with open("file.txt", 'r') as fptr:
            data = fptr.readlines()
            for i in data:
                id = len(self.candidate)
                space_line = i.split(" ")
                # print(space_line)
                voter_data = space_line[2].split("@")

                v_data = []
                # print(voter_data)
                for i in range(1, len(voter_data)):
                    new_s = voter_data[i].replace("\n","")
                    v_data.append(new_s)
                    if v_data[i-1] == "":
                        del v_data[i-1]
                data_form = {id: {"name": space_line[0], "v_mark": int(space_line[1]), "voter": v_data}}
                self.candidate.update(data_form)