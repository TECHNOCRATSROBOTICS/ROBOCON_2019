import tkinter
from motor import motor
import dimensions
class object:

    def __init__(self, shape = 'rectangle', no_of_wheels = 4, width = 50, height = 50, x_offset = 0, y_offset = 0, radius = 0):
        self.shape = shape
        self.no_of_wheels = no_of_wheels
        self.x1 = x_offset
        self.y1 = y_offset
        self.x2 = x_offset + width
        self.y2 = y_offset + height
        if shape == 'rectangle' : self.init_rect_model(width, height, x_offset, y_offset)
        elif shape == 'line' : self.bot_line = self.line(radius, width, x_offset, y_offset)

    class point:
        def __init__(self, r, xc, yc):
            dimensions.point = point
            self.xc = xc
            self.yc = yc
            self.r = self.r
        def draw_pt(self, canvas):
            self.point_obj = canvas.create_oval(self.xc - self.r, self.yc - self.r, self.xc + self.r, self.yc + self.r)
            return point_obj
        def move(self, canvas, dx, dy):
            canvas.move(self.point_obj, dx, dy)
            self.xc += dx
            self.yc += dy
            return draw_pt(canvas)
            
            
    class line(object, point):
    
        def __init__(self, r, d, xc, yc):
            dimensions.line = line
            self.p1 = super().point(r, xc, yc)
            self.p2 = super().point(r, xc+d, yc)
            self.line_obj = canvas.create_line(xc, yc, xc+d, yc)
            
        def move_line(self, canvas, dx1, dy1, dx2, dy2):
            canvas.delete(self.line_obj)
            p1.move(canvas, dx1, dy1)
            p2.move(canvas, dx2, dy2)
            self.draw_line(canvas)

        def draw_line(self, canvas):
            self.line_obj = canvas.create_line(self.p1.xc, self.p1.yc, self.p2.xc, self.p2.yc)
            return self.line_obj
            
            
    def init_rect_model(self, width = 50, height = 50, x_offset = 0, y_offset = 0):
        '''
        ul : upper left      dl : down left
        ur : upper right     dr : down right
        
        MODEL : 
        
        ul----------ur
        |            |
        |            |
        |    BOT     |
        |            |
        |            |
        dl-----------dr
        '''
        #Setting up motors : 
        self.ul_motor = motor()
        self.ur_motor = motor()
        self.dl_motor = motor()
        self.dr_motor = motor()
        
        #setting coordinates:
        self.width = width
        self.height = height
        "These parameters will remain constant."
        
        #Offsets:
        "This is the factor which will change the position of the bot."
        self.x_offset = x_offset
        self.y_offset = y_offset
        
        
    def draw_rect(self, canvas):
        
        #returning lines, so that, it can be deleted.
        
        create_line = canvas.create_line
        l1 = create_line(self.x1, self.y1, self.x2, self.y1)
        l2 = create_line(self.x2, self.y1, self.x2, self.y2)
        l3 = create_line(self.x2, self.y2, self.x1, self.y2)
        l4 = create_line(self.x1, self.y2, self.x1, self.y1)
    
        return [l1, l2, l3, l4]
    
    
    def mv_rectangle_bot(self, bot_rect, canvas, dx1, dy1, dx2, dy2):
        for i in bot_rect:
            canvas.delete(i)
        self.x1 += dx1
        self.y1 += dy1
        self.x2 += dx2
        self.y2 += dy2
        l1 = canvas.create_line(self.x1, self.y1, self.x2, self.y1)
        l2 = canvas.create_line(self.x2, self.y1, self.x2, self.y2)
        l3 = canvas.create_line(self.x2, self.y2, self.x1, self.y2)
        l4 = canvas.create_line(self.x1, self.y2, self.x1, self.y1)
        return [l1, l2, l3, l4]
        
        
    def mv_pt(canvas, pt, dx, dy):
        canvas.delete(pt)
        
