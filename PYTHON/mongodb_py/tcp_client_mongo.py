import socket
import json
import pymongo

connection =pymongo.MongoClient("localhost", 27017)
database =connection["nccdip2"]
col =database["user_info"]


def email_exit_check(email_to_check):

    for i in col.find({}, {"email": 1}):
        if email_to_check == i["email"]:
            return -1

    return 1

def enter_data():
    sms = input("Enter some data to send:")
    tcp_client = TCPclient(sms)


class TCPclient():
    def __init__(self, sms):
        self.target_ip = 'localhost'
        self.target_port = 9998
        self.input_checking(sms)

    def client_runner(self):

        client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        client.connect((self.target_ip, self.target_port))

        # client.send(self.client_sms)
        #
        #     received_from_server = client.recv(4096)
        #
        #     recv_sms = received_from_server.decode("utf-8")
        #
        #     print("$:", recv_sms)
        #
        #     client.close()
        return client  # to send and received data

    def input_checking(self, sms):
        if sms == "gad":
            self.get_all_data(sms)

        elif sms == "login":
            self.login(sms)

        elif sms == "reg":
            self.register(sms)
        else:
            print("Invalid Option")

    def get_all_data(self, sms):
        client = self.client_runner()
        sms = bytes(sms, "utf-8")
        client.send(sms)
        received_from_server = client.recv(4096)
        # print(received_from_server.decode("utf-8"))

        dict_data: dict = json.loads(received_from_server.decode("utf-8"))
        print(type(dict_data))
        print(dict_data)
        client.close()

    def login(self, info):
        try:
            print("This is login Form")
            l_email = input("Enter your email to login:")
            l_pass = input("Enter your password to login:")

            client = self.client_runner()
            sms = info + ' ' + l_email + ' ' + l_pass  # login email password
            sms = bytes(sms, "utf-8")
            client.send(sms)
            received_from_server = client.recv(4096)
            print(received_from_server.decode("utf-8"))
            client.close()

        except Exception as err:
            print(err)

    def register(self, info):
        print("This is registration option.")
        r_email = input("Enter your email to register:")
        r_pw = input("Enter your password:")
        flag = email_exit_check(r_email)
        if flag == 1:
            client = self.client_runner()
            sms = info + ' ' + r_email + ' ' + r_pw #register email pw
            sms = bytes(sms, 'utf-8')
            client.send(sms)
            rcv_from_server = client.recv(4096)
            print(rcv_from_server.decode('utf-8'))
            client.close()
        else:
            print("Email already exit:")
            self.register(info)

if __name__ == "__main__":
    while True:
        enter_data()
