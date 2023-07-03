import pygame, sys
from game import *
# from grid import Grid
# from blocks import *

pygame.init #initialises the pygme library
dark_blue = (44,44,127)

screen = pygame.display.set_mode((300,600)) #create a display surface object called screen, where the setmode takes a tupple as input and first is w and 2nd is h. 

pygame.display.set_caption("Tetris")

clock = pygame.time.Clock() #takes care of the frame rate.

game = Game()
# game_grid = Grid()

# block = Tblock() #creating a block object of the LBlock class. 
# block.move(4,3)

# game_grid.print_grid()

while True: #runs continousluntil the game is closed. 
    for event in pygame.event.get(): #gets all the events that pygame recognizes and happened since the last time the while loop run, then it oputs in a list. 
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit() # exits the system. 

    screen.fill(dark_blue)
    # game_grid.draw(screen)
    # block.draw(screen) #draws the block.
    game.draw(screen)

    pygame.display.update() #takes all the changes in the game object and draws a picture from that. 
    clock.tick(60) # this sets the speed of the game. (refresh rate)


 
