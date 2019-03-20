from inputs import get_gamepad
import time
import threading
global stepperState
stepperState = 0
#import serial
#from pyserial import Serial

#global ser
#ser = serial.Serial('/dev/ttyACM0', 9600)
#ser = serial.Serial('COM16', 9600)
#from numpy import interp
#def rangeMap(num):
#	return int(interp(num,[-32768,32768],[1,10]))

if(stepperState is 1):
        print("stepper ACTIVATED")

def readGP():
    while 1:
        global BTN,state,types
        event = get_gamepad()
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
                   # ser.write('U'.encode())
                elif(BTN=='ABS_HAT0Y' and state==1):    
                    print("DOWN Button pressed")
                   # ser.write("D".encode())
                elif(BTN=='ABS_HAT0X' and state==-1):    
                    print("LEFT Button pressed")
                    #ser.write("LEFT Button pressed".encode())
                elif(BTN=='ABS_HAT0X' and state==1):    
                    print("RIGHT Button pressed")
                    #ser.write("LEFT Button pressed".encode())
                else:
                    print(BTN,state)
                    #ser.write(BTN.encode())
                    #ser.write(char(abs(state)))
                    #if (BTN is ('ABS_X'or'ABS_Y'or'ABS_RX'or'ABS_RY')):
                            #ser.write(chr(rangeMap(state)).encode())
                    #else:
                            #ser.write(chr((state)).encode())

                        # ACTIVATES STEPPER MOTOR
                        #ser.write('s')
                     
                        #print(state) # ser.write(state)
                        
                        #time.sleep(10)
            elif(types=='Key'):
                print(BTN,"lund lelo")
                #ser.write(BTN.encode())
                #ser.write("Button Pressed".encode())
              
               # if(BTN is 'ABS_RX' or BTN is 'ABS_RY'):

                #        # ACTIVATES 
                        
                        
        else:
            print("Button Not pressed".encode())
           # ser.write("0".encode())
        #time.sleep(1)

BTN='None'
state='None'
types='None'
key=0
t1 = threading.Thread(target = readGP)
t2 = threading.Thread(target = monitor)
t1.daemond = True
t1.daemond = True
t1.start()
t2.start()
    
