# from grid import Grid
from colors import Colors
from position import Position
import pygame

class Block:
    def __init__(self, id):
        #we need to determine what info each black will have. 
        self.id = id
        self.cells = {} #this is a dictionary that stores the occupied cells for each rotation of the block in the cell. 
        self.cell_size = 30
        self.row_offset = 0
        self.column_offset = 0
        self.rotation_state = 0
        self.colors = Colors.get_cell_colors()
    
    def move(self, rows, columns):
        self.row_offset += rows
        self.column_offset += columns

    def get_cell_positions(self): #this method will return the positions of the occupied cells weith the offst applied in a list. 
        #this gets the default cell position fpr the currnt rotation state. 
        tiles = self.cells[self.rotation_state]
        moved_tiles = []
        for position in tiles:
            position = Position(position.row + self.row_offset, position.column + self.column_offset)
            moved_tiles.append(position)
        return moved_tiles



    #responsible for draeing the grid on the screen. 
    def draw(self, screen): #retrieve the list of position sfor the current position of the tetramino. 
        tiles = self.get_cell_positions()
        for tile in tiles:
            tile_rect = pygame.Rect(tile.column * self.cell_size + 1, tile.row * self.cell_size +1, 
            self.cell_size - 1, self.cell_size -1)
            pygame.draw.rect(screen, self.colors[self.id], tile_rect) #takes in the display surface, the color, and the cordinates of the rectangle to be made as the attributes. 


    

        