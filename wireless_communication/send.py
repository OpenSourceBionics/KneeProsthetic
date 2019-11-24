import socket
import Adafruit_ADS1x15
import time


# Configure wireless connection with server (board on leg)
HOST = "155.98.5.226"
PORT = 5005
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((HOST, PORT))

# Create an ADS1115 ADC (16-bit) instance.
adc = Adafruit_ADS1x15.ADS1115()

GAIN = 1

while True:
	# Read all the ADC channel values in a list.
   	values = [0]*2
    	for i in range(2):
        	# Read the specified ADC channel using the previously set gain value.
        	values[i] = adc.read_adc(i, gain=GAIN)
       		# Note you can also pass in an optional data_rate parameter that controls
        	# the ADC conversion time (in samples/second). Each chip has a different
        	# set of allowed data rate values, see datasheet Table 9 config register
        	# DR bit values.
        	#values[i] = adc.read_adc(i, gain=GAIN, data_rate=128)
        	# Each value will be a 12 or 16 bit signed integer value depending on the
        	# ADC (ADS1015 = 12-bit, ADS1115 = 16-bit).
   	# Print the ADC values.
    	command = "Y : " + str(values[0]) + ", Button : " + str(values[1])
   	s.send(command)
   	# delay
    	time.sleep(0.5)

	# reply from server
	#reply = s.recv(1024)
	#if reply == "Terminating":
	#	break
	#print reply

