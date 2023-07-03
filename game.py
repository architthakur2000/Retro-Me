from grid import Grid
from blocks import *
import random #the random module.

class Game:
    def __init__(self):
        #creates and holds a grid. 
        self.grid = Grid() #a grid attribute
        #create an attribute to hold the current block, that is visible on the screen. 
        self.blocks = [Iblock(), Jblock(), Lblock(), Oblock(), Sblock(), Tblock(), Zblock()]
        self.current_block = self.get_random_block()
        self.next_block = self.get_random_block()

    #this method creates a random block from this list. 
    def get_random_block(self):
        if len(self.blocks) == 0:
            self.blocks = [Iblock(), Jblock(), Lblock(), Oblock(), Sblock(), Tblock(), Zblock()]
     
        block = random.choice(self.blocks)
        #now, we remove the block, so the next time this method, is call it is not repeating the blick. 
        self.blocks.remove(block)
        return block

    def draw(self, screen):
        self.grid.draw(screen) #this draws the grid on the screen.
        self.current_block.draw(screen) # this draws the current block on the scrren. 


