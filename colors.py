class Colors:

    dark_grey = (26, 31, 40)
    green = (47, 230, 23)
    red = (232, 18, 18)
    orange = (226, 116, 17)
    yellow = (237, 234, 4)
    purple = (166, 0, 247)
    cyan = (21, 204, 209)
    blue = (13, 64, 216)

    #method which return the list of this color in a specific order. 

    @classmethod
    # This is a python decorator that allows me to define a method that can be called on a class
    # rather than on an instance of a class. 
    def get_cell_colors(cls):#cls is a reference to the class itself which allows us to use class level attributes and methods. 
         return [cls.dark_grey, cls.green, cls.red, cls.orange, cls.yellow, cls.purple, cls.cyan, cls.blue]
