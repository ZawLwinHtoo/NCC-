import socket

import pymongo

import mongodb_py

connection = pymongo.MongoClient("localhost", 27017)
database = connection["nccdip2"]
collection = database["1-server"]
class TCP_server():
    def __init__(self):
        self.server_ip = 'localhost'
        self.server_port = 9988
        self.to_save = {}

    def main(self):
        server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        server.bind((self.server_ip, self.server_port))
        server.listen()
        print("Server listen on port: {} - ip: {}".format(self.server_port, self.server_ip))
        try:
            while True:
                print("**")
                client, add = server.accept()
                print("Accepted information from : {} - {} ".format(add[0], add[1]))
                self.handle_client(client)
        except Exception as err:
            print(err)

    def handle_client(self, client_socket):
        with client_socket as sock:
            client_receive = sock.recv(1024)
            received_data = client_receive.decode("utf-8")
            if received_data == "gad":
                for i in collection.find({}, {"_id": 0, "data": 1}):
                    print(i["data"])
            else:
                dataform = {"data": received_data}
                ids = collection.insert_one(dataform)

            print("Received data from client:", received_data)
            message = "Server received it >> " + received_data
            to_send = bytes(message, 'utf-8')
            sock.send(to_send)

if __name__ == '__main__':
    tcp_server = TCP_server()
    tcp_server.main()
