import pygame
from colors import Colors
#create a grid class, with a self object. 
class Grid:
    #need toi know how many rows and columns needed.
    def __init__(self):
        self.num_rows = 20
        self.num_cols = 10
        self.cell_size = 30 #the size of the each block of a grid. 
        self.grid = [[0 for j in range(self.num_cols)] for i in range(self.num_rows)] #using list comprehension to create a list of 0's
        self.colors = Colors.get_cell_colors()
    
    def print_grid(self): # method to print the grid in the window. 
        for row in range(self.num_rows):
            for column in range(self.num_cols):
                print(self.grid[row][column], end = " ") #why do we write (,end = " ")? 
            print()  

    def draw(self, screen):
        for row in range(self.num_rows): 
            for column in range(self.num_cols):
                cell_value = self.grid[row][column]
                cell_rect = pygame.Rect(column*self.cell_size + 1, row*self.cell_size + 1,
				self.cell_size -1, self.cell_size -1)
                pygame.draw.rect(screen, self.colors[cell_value], cell_rect)