package MathUtility;

import java.util.Random;

public final class Noise {
	public enum NoiseType {Perlin, Simplex, Random};
	
	public static int seed = 0;
	private static Random random = new Random(seed);
	
	public static void InitailizeRandom() {
		random = new Random(seed);
	}
	
	public static void InitializeRandom(int seed) {
		random = new Random(seed);
	}
	
	public static float Perlin(int x, int y) {
		return (float) Perlin.noise(x, y, 100);
	}
	
	public static float Simplex(int x, int y) {
		return 0;
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
				noise = Noise.Perlin(x, y);
				break;
			case Simplex:
				noise = Noise.Simplex(x, y);
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
