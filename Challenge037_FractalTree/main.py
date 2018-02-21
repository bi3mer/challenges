#!/usr/bin/python
# @author: Colan Biemer
# based on https://www.pygame.org/docs/ref/draw.html

import pygame
import Config
from fractal_tree import draw_fractal_tree


def main():
	# Initialize the game engine
	pygame.init()

	# Set the height and width of the screen
	size = [400, 300]
	screen = pygame.display.set_mode(size)
	
	pygame.display.set_caption("Fractal Tree")
	 
	#Loop until the user clicks the close button.
	done = False
	clock = pygame.time.Clock()

	while not done:
		# This limits the while loop to a max of 10 times per second.
		# Leave this out and we will use all CPU we can.
		clock.tick(10)
		 
		for event in pygame.event.get(): 
			if event.type == pygame.QUIT: 
				done = True
			if event.type == pygame.KEYDOWN:
				if event.key == pygame.K_ESCAPE:
					done = True
		 
		# Clear the screen and set the screen background
		screen.fill(Config.BLACK)
		draw_fractal_tree(pygame, screen)
		
		# Go ahead and update the screen with what we've drawn.
		# This MUST happen after all the other drawing commands.
		pygame.display.flip()
 
# Be IDLE friendly
pygame.quit()

if __name__ == '__main__':
	main()