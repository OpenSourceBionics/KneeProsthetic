import socket
import serial
import time

HOST = "INSERT SERVER IP ADDRESS"
PORT = 5005
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
print "socket created"

# connect with teensy
ser = serial.Serial('/dev/tty/ACM0', 9600)
time.sleep(.5)

# managing error exception
try:
	s.bind((HOST,PORT))
except socket.error:
	print "bind Failed"

s.listen(1)
print "Socket awaiting mesesages"
(conn, addr) = s.accept()
print "connected"

# awaiting message
while True:
	data = conn.recv(1024)
	print data
	
	# send data to teensy
	ser.write(str(data))
	time.sleep(.1)
	
	#print "I sent a message back in response to: " + data

	# process message
	#if data == "Hello":
	#	reply = "Hi, back!"
	#elif data == "quit":
	#	conn.send("Terminating")
	#	break
	#else:
	#	reply = "Unknown command"

	# send reply
	#conn.send(conn.recv(1024))

conn.close()

