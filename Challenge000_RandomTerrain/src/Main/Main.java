package Main;

import org.lwjgl.opengl.Display;
import org.lwjgl.opengl.GL11;
import org.lwjgl.opengl.GL30;
import org.lwjgl.util.vector.Vector3f;

import MathUtility.*;
import RenderEngine.DisplayManager;
import RenderEngine.EntityRenderer;
import RenderEngine.ModelLoader;
import entities.Camera;
import entities.Entity;
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
		StaticShader shader = new StaticShader();
		EntityRenderer renderer = new EntityRenderer(shader);
		
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
		TexturedModel t_model = new TexturedModel(
				model, 
				new ModelTexture(loader.loadTexture("creative-commons-license-symbol")));
		Vector3f position = new Vector3f(0, 0, -1);
		
		Entity entity = new Entity(t_model, position, 100, 0, 0, 1);
		
		Camera camera = new Camera();
		
		while(!Display.isCloseRequested()) {
//			entity.increasePosition(0, 0, -1);
//			entity.increaseRotation(1, 0, 0);
			camera.move();
			
			renderer.prepare();
			shader.start();
			shader.loadViewMatrix(camera);
			renderer.render(entity, shader);
			
			shader.stop();
			DisplayManager.UpdateDisplay();
		}
		
		shader.cleanUp();
		loader.cleanUp(); 
		DisplayManager.CloseDisplay();
	}
}
