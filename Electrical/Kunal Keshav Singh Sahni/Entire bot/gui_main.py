import tkinter
import dimensions
import bot_structure
import time
from random import randint as random
def mv(window, bot_rect):
    window.canvas.move(bot_rect, 1, 0)
class gui :
    def __init__(self, root):
        self.root = root
        self.canvas = tkinter.Canvas(self.root, width = dimensions.root_x, height = dimensions.root_y)
        self.canvas.pack()

root = tkinter.Tk()
root.geometry(str(dimensions.root_x)+"x"+str(dimensions.root_y))

window = gui(root)

bot = bot_structure.object('line', dimensions.no_of_wheels, 
                                        dimensions.bot_width, 
                                        dimensions.bot_height, 
                                        dimensions.x_offset,
                                        dimensions.y_offset, 
                                        dimensions.radius)
bot_rect = bot.draw_rect(window.canvas)
sign = -1
x = random(-1, 1)
for i in range(10000):
    time.sleep(1/dimensions.speed)
    bot_rect = bot.mv_bot(bot_rect, window.canvas, x, 1, x, 1)
    root.update()
root.mainloop()
