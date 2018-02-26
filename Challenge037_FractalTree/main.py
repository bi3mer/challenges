#!/usr/bin/python
# @author: Colan Biemer
# based on https://www.pygame.org/docs/ref/draw.html

import pygame
import Config
from math import pi
from fractal_tree import draw_fractal_tree

def lerp(minimum, maximum, percent):
	return minimum + percent * (maximum - minimum)

def update_step(current_step, increment, direction):
	new_step = current_step + (increment * direction)

	if new_step <= 0:
		direction = 1
		new_step  = 0
	elif new_step >= 1:
		direction = -1
		new_step  = 1

	return new_step, direction

def main():
	# Initialize the game engine
	pygame.init()

	# Set the height and width of the screen
	size = [800, 600]
	screen = pygame.display.set_mode(size)
	
	pygame.display.set_caption("Fractal Tree")
	 
	#Loop until the user clicks the close button.
	done = False
	clock = pygame.time.Clock()
	current_step = 0
	direction    = 1

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

		# draw fractal tree at bottom middle of the screen with the first line
		# draw straight up ata 90 degree angle
		delta_angle = lerp(Config.MIN_ANGLE, Config.MAX_ANGLE, current_step)
		draw_fractal_tree(pygame, screen, [size[0]/2.0, size[1]], Config.LINE_LENGTH, delta_angle, pi/2.0)
		
		# Go ahead and update the screen with what we've drawn.
		# This MUST happen after all the other drawing commands.
		pygame.display.flip()

		current_step, direction = update_step(current_step, Config.STEP, direction)
 
# Be IDLE friendly
pygame.quit()

if __name__ == '__main__':
	main()
