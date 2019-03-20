import pygame
import time
pygame.init()
pygame.joystick.init()

joystick = pygame.joystick.Joystick(0)
joystick.init()

print('Initialised Joystick : %s' % joystick.get_name())
print('Press ESC to stop')

screen = pygame.display.set_mode((100,100))

# get count of joysticks=1, axes=27, buttons=19 for DualShock 3

joystick_count = pygame.joystick.get_count()
print("joystick_count")
print(joystick_count)
print("--------------")

numaxes = joystick.get_numaxes()
print("numaxes")
print(numaxes)
print("--------------")

numbuttons = joystick.get_numbuttons()
print("numbuttons")
print(numbuttons)
print("--------------")

loopQuit = False
while loopQuit == False:

# test joystick axes
        for i in range(0,4):
                pygame.event.pump()
                axis = joystick.get_axis(i)
                print("Axis " + str(i) + " = " + str(axis))
                
        print("--------------")
        

# test controller buttons
        for i in range(0,numbuttons):
                pygame.event.pump()
                button = joystick.get_button(i)
                print("Button " + str(i) + " = " + str(button))
        print("--------------")
       
        
# quit if escape pressed
        for event in pygame.event.get():
                if event.type == pygame.KEYDOWN:
                        if event.key == pygame.K_ESCAPE:
                                loopQuit = True

        pygame.display.update()
        time.sleep(2)

pygame.quit()
