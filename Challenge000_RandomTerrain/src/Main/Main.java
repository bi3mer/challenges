package Main;

import org.lwjgl.opengl.Display;
import org.lwjgl.opengl.GL11;
import org.lwjgl.opengl.GL30;

import MathUtility.*;
import RenderEngine.DisplayManager;
import RenderEngine.ModelLoader;
import RenderEngine.RawModel;
import RenderEngine.Renderer;
import shaders.StaticShader;

public class Main {
	// Configuration
	static final int width  = 10;
	static final int height = 10;
	static final int seed   = 0;
	static final Noise.NoiseType noiseType = Noise.NoiseType.Random;
	static final boolean render3d = true;
	static final float amplitude = 2.0f;
	
	// Generate based on configured values
	public static void main(String[] args) {
		 Noise.seed = seed;
		
		// Initialize noise matrix
		float[][] noise = new float[height][width];
		
		for(int y = 0; y < height; ++y) {
			for(int x = 0; x < width; ++x) {
				noise[y][x] = Noise.GenerateNoise(x, y, noiseType) * amplitude;
			}
		}
		
		// start renderer
		DisplayManager.CreateDisplay();
		
		ModelLoader  loader = new ModelLoader();
		Renderer renderer   = new Renderer();
//		StaticShader shader = new StaticShader();
		
		float[] quad_vertices = {
			-0.5f, 0.5f, 0f,
			-0.5f, -0.5f, 0f,
			0.5f, -0.5f, 0f,
			0.5f, -0.5f, 0f,
			0.5f, 0.5f, 0f,
			-0.5f, 0.5f, 0f
		};
		System.out.println(GL11.glGetString(GL11.GL_VERSION));
		
		RawModel model = loader.loadToVAO(quad_vertices);
		
		while(!Display.isCloseRequested()) {
			renderer.prepare();
//			shader.start();
			renderer.render(model);
			
//			shader.stop();
			DisplayManager.UpdateDisplay();
		}
		
//		shader.cleanUp();
		loader.cleanUp(); 
		DisplayManager.CloseDisplay();
	
//		 if(render3d == true) {
//		 	 // code to render 3d version of the noise using
//			 // it as a height map.
//		 } else {
//			 // code to render 2d image of the map,
//			 // preferably with blending.
//		 }
	}
}
