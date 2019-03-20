from inputs import get_gamepad
import time
import threading
import serial
from numpy import interp

#def rangeMap(num):
#	return int(interp(num,[-32768,32768],[0,255]))

global ser
#ser = serial.Serial('/dev/ttyACM0', 9600)
ser = serial.Serial('COM9', 9600)


def readGP():
    while 1:
        global BTN,state,types
        events = get_gamepad()
        for event in events:
            BTNc=event.code
            if BTNc!='SYN_REPORT':
                types=event.ev_type
                BTN=event.code 
                state=event.state
        #time.sleep(1)

def monitor():
    while 1:
        #print(BTN,state)
        if(state!=0):
            if(types=='Absolute'):
                if(BTN=='ABS_HAT0Y' and state==-1):    
                    print("UP Button pressed")
                    ser.write('U'.encode())
                elif(BTN=='ABS_HAT0Y' and state==1):    
                    print("DOWN Button pressed")
                    ser.write("D".encode())
                elif(BTN=='ABS_HAT0X' and state==-1):    
                    print("LEFT Button pressed")
                    ser.write("L".encode())
                elif(BTN=='ABS_HAT0X' and state==1):    
                    print("RIGHT Button pressed")
                    ser.write("R".encode())
                else:
                        print(BTN,state)
                    #ser.write(chr(rangeMap(state)).encode())
                       # ser.write(chr(rangeMap(state)).encode())
                    # never ever ever ever fucking ser.write() this shit cause it will cause error
                    #ser.write(BTN.encode())
                    #ser.write(chr(abs(state)))
                    #if (BTN is ('ABS_X'or'ABS_Y'or'ABS_RX'or'ABS_RY')):
                    #        ser.write(chr(rangeMap(state)).encode())
                    #else:
                     #       ser.write(chr(state).encode())
            elif(types=='Key'):
                print(BTN)
                if BTN is 'BTN_NORTH':
                        ser.write('N'.encode())
                    
                if BTN is 'BTN_SOUTH':
                        ser.write('S'.encode())
                    
                if BTN is 'BTN_WEST':
                        ser.write('W'.encode())
                    
                if BTN is 'BTN_EAST':
                        ser.write('E'.encode())
                if BTN is 'BTN_TR':
                        ser.write('s'.encode())
                                    #ser.write("Button Pressed".encode())
        else:
            print("Button Not pressed".encode())
            ser.write("0".encode())
        #time.sleep(1)

BTN='None'
state='None'
types='None'
key=0
t1 = threading.Thread(target = readGP)
t2 = threading.Thread(target = monitor)
t1.daemond = True
t2.daemond = True
t1.start()
t2.start()
    
