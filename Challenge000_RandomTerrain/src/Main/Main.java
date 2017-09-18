package Main;

import org.lwjgl.opengl.Display;
import org.lwjgl.opengl.GL11;
import org.lwjgl.opengl.GL30;

import MathUtility.*;
import RenderEngine.DisplayManager;
import RenderEngine.EntityRenderer;
import RenderEngine.ModelLoader;
import models.RawModel;
import models.TexturedModel;
import shaders.StaticShader;
import textures.ModelTexture;

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
		EntityRenderer renderer = new EntityRenderer();
		StaticShader shader = new StaticShader();
		
		float[] quad_vertices = {
			-0.5f, 0.5f, 0f,  // v0
			-0.5f, -0.5f, 0f, // v1
			0.5f, -0.5f, 0f,  // v2
			0.5f, 0.5f, 0f    // v3
		};
		
		int[] quad_indices = {
				0, 1, 3,
				3, 1, 2
		};
		
		float[] uvs = {
			0f, 0f,
			0f, 1f,
			1f, 1f,
			1f, 0f
		};
		
		System.out.println(GL11.glGetString(GL11.GL_VERSION));
		
		RawModel model = loader.loadToVAO(quad_vertices, quad_indices, uvs);
		ModelTexture texture = new ModelTexture(loader.loadTexture("creative-commons-license-symbol"));
		TexturedModel t_model = new TexturedModel(model, texture);
		
		while(!Display.isCloseRequested()) {
			renderer.prepare();
			shader.start();
			renderer.render(t_model);
			
			shader.stop();
			DisplayManager.UpdateDisplay();
		}
		
		shader.cleanUp();
		loader.cleanUp(); 
		DisplayManager.CloseDisplay();
	}
}
