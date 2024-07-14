import socket
import threading

def handler(client):
    while True:
        data = client.recv(1024)
        print(data.decode('UTF-8'))
        msg_encode = "message received".encode('UTF-8')

        client.sendall(msg_encode)

        client.close()


    
def main():

    s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)


    s.bind(("192.168.1.7",5000))  # adderss and the port 5000

    s.listen()   

    while True:
        client ,address = s.accept() 

        print(f"connected by {address}")

        
        threading.Thread(target=handler,args=(client,)).start()


      
        client.close()





if __name__ == "__main__":
    main()
