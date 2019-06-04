#!/usr/bin/env python
#(1)listen on the port specified from command line / pass port# argv
from socket import*
from sys import argv
from time import ctime#for the time
#passing two argument filename argv[0] and portnumber argv[1]
if(len(argv)==2):
    portnumber=int(argv[1])
else:
    portnumber=12000
#HTTP uses TCP to make sure nothing drop
Socket=socket(AF_INET,SOCK_STREAM)#create socket for the proxy server
Socket.bind(('',portnumber))#'' connect to local host
Socket.listen(1) #wait for client connection, listening for incoming request
print("Wait for client connection")
while True:
    connectionSocket,clientaddress=Socket.accept()
    print("Client is now connected")
    httprequest=connectionSocket.recv(1024).decode()#decode the message received from the client
    #accept HTTP request from client
    #check properly-formatted HTTP request
    #1.method(GET,POST,PUT...)&2.URL&3.Protocal server HTTP/1.1
    request=httprequest.split()#split the http request into different part
    httpmethod=request[0]
    urllink=request[1]
    if request[2]=='HTTP/1.1':#http version must be 1.1
        version=request[2]
    else:
        print("incorrect HTTP version")
    #messagebody is empty
    #just accepting request return a status code
    #Now instead of just accepting request it will forward the request to the remote server
    newurl=urllink.replace('http://','')
    port=80
    ipv=(newurl)#it will be www.google.com without the http:// in front
    remotesocket =socket(AF_INET,SOCK_STREAM)#create a socket/door for remote server connect to it
    remotesocket.connect((ipv,port))#remote socket connect to www.google.com or other website 
    print("Connected to the remote server")
    #GET / HTTP/1.1
    #Host: www.example.com
    #Connection: close
    remotesocket.send(httpmethod.encode())
    remotesocket.send(" / ".encode())
    remotesocket.send(version.encode())
    remotesocket.send("\r\n".encode())
    remotesocket.send("Host:".encode())
    remotesocket.send(newurl.encode())
    remotesocket.send("\r\n\r\n".encode())
    remotesocket.send("\nConnection: close".encode())
    #Above is the http request to the remote server
    print("Request send to remote server")
    #response receive from the socket
    responsefromremoteserver=remotesocket.recv(1024)
    print ("Response from the remote server is received")
    #now send the response to the client without decoding, decode in the client
    connectionSocket.send(responsefromremoteserver)
    print("Response forward to client")
    print("Date: ",ctime())#general header print time
    connectionSocket.close()

#I used these websites below to help me with the project
#https://docs.python.org/3/library/socket.html
#https://serverfault.com/questions/570761/how-to-duplicate-tcp-traffic-to-one-or-multiple-remote-servers-for-benchmarking

            

