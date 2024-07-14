import socket 


client = socket.socket(socket.AF_INET,socket.SOCK_STREAM)


client.connect(("192.168.1.7",5000))


msg = str(input("please enter the message that u want to send :"))

msg_encode = msg.encode('UTF-8')

client.send(msg_encode)

rodata = client.recv(1024)

print(f"192.168.1.7 is sending to u {rodata.decode('UTF-8')}")

client.close()