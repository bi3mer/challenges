package MathUtility;

import java.util.Random;

public final class Noise {
	public enum NoiseType {Perlin, Simplex, Random};
	
	public static int seed = 0;
	private static Random random = new Random(seed);
	private static PerlinNoise Perlin = new PerlinNoise(seed);
	
	public static void InitailizeRandom() {
		random = new Random(seed);
	}
	
	public static void InitializeRandom(int seed) {
		random = new Random(seed);
		Perlin = new PerlinNoise(seed);
	}
	
	// get float between -1 and 1
	public static float Random() {
		return random.nextFloat() * 2f - 1;
	}
	
	// Generate noise based on coordinates and enum which defines
	// the function to be called. 
	public static float GenerateNoise(int x, int y, NoiseType noiseType) {
		float noise = 0;
		
		switch(noiseType) {
			case Perlin:
				noise = Perlin.GetNoise(x, y);
				break;
			case Simplex:
				noise = (float) SimplexNoise.noise(x, y);
				break;
			case Random:
				noise = Noise.Random();
				break;
			default:
				System.out.println("Noise type not found");
				break;
		}
		
		return noise;
	}
}
