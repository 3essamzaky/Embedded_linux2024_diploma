import socket


s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)


s.bind(("192.168.1.7",5000))  # adderss and the port 5000

s.listen(5)   #max 5 client can be access the server

while True:
    client ,address = s.accept() #client is the socket that come and the address is the address that the clint get out from his divice

    rodata = client.recv(1024)
    print(f"{address} is sending to you this message {rodata.decode('UTF-8')}")

    msg = str(input("please enter the message that you want to send: "))
    msg_encode = msg.encode('UTF-8')

    client.send(msg_encode)
    client.close()
    
