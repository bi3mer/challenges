import Config
import math

def draw_fractal_tree(pygame, screen, start_pos, line_length, current_angle):
	end_position = [
		start_pos[0] + (line_length * math.cos(current_angle)),
		start_pos[1] + (line_length * math.sin(current_angle))]
	pygame.draw.line(screen, Config.WHITE, start_pos, end_position, Config.LINE_WIDTH)

	line_length *= Config.LINE_LENGTH_DIVISOR

	if line_length < Config.MIN_LINE_LENGTH:
		draw_fractal_tree(pygame, screen, end_position, line_length, current_angle + Config.ANGLE)
		draw_fractal_tree(pygame, screen, end_position, line_length, current_angle - Config.ANGLE)	
