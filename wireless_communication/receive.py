import socket

HOST = "155.98.5.226"
PORT = 5005
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
print "socket created"

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

