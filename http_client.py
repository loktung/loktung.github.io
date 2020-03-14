#Basic version

#TCPclient

#Test out purpose of the code with a client 

from socket import*

serverName='localhost'

serverPort=12000

clientSocket=socket(AF_INET, SOCK_STREAM)

clientSocket.connect((serverName, serverPort))

httprequest=input('Input HTTP request <method> <URL> <version>:')

clientSocket.send(httprequest.encode())#send to request to the proxy 

#below decode and print the response receive from proxy



print(clientSocket.recv(1024).decode())

#it should print the status

clientSocket.close()
