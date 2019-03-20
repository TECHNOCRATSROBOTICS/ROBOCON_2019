class motor:
    def __init__(self, speed = 0):
        """
        Considering the pwm as speed.
        """
        self.speed = speed
    def get_speed(self):
        return self.speed
    def set_speed(self, speed):
        self.speed = speed

