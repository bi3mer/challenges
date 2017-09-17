package Main;

import MathUtility.*;

public class Main {
	// Configuration
	static int width  = 10;
	static int height = 10;
	static int seed   = 0;
	static Noise.NoiseType noiseType = Noise.NoiseType.Random;
	static boolean render3d = false;
	
	// Generate based on configured values
	public static void main(String[] args) {
		 Noise.seed = seed;
		
		// Initialize noise matrix
		float[][] noise = new float[height][width];
		
		for(int y = 0; y < height; ++y) {
			for(int x = 0; x < width; ++x) {
				noise[y][x] = Noise.GenerateNoise(x, y, noiseType);
			}
		}
		
		// TODO: update with multiple passes to smooth out
		//       the noise.
		for(int y = 0; y < height; ++y) {
			for(int x = 0; x < width; ++x) {
				System.out.print(noise[y][x] + " ");
			}
			
			System.out.println();
		}
		
		 if(render3d == true) {
		 	 // code to render 3d version of the noise using
			 // it as a height map.
		 } else {
			 // code to render 2d image of the map,
			 // preferably with blending.
		 }
	}
}
