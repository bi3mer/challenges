package Main;

import org.lwjgl.opengl.Display;
import org.lwjgl.opengl.GL11;
import org.lwjgl.opengl.GL30;
import org.lwjgl.util.vector.Vector3f;

import MathUtility.*;
import RenderEngine.DisplayManager;
import RenderEngine.EntityRenderer;
import RenderEngine.ModelLoader;
import Terrain.Terrain;
import entities.Camera;
import entities.Entity;
import models.RawModel;
import models.TexturedModel;
import shaders.StaticShader;
import textures.ModelTexture;

public class Main {
	// Configuration
	static final int size  = 40;
	static final int seed   = 0;
	static final Noise.NoiseType noiseType = Noise.NoiseType.Random;
	static final boolean render3d = true;
	static final float amplitude = 0.5f;
	static final float scale = 10f;
	
	// Generate based on configured values
	public static void main(String[] args) {
		 Noise.seed = seed;
		
		// Initialize noise matrix
		float[][] noise = new float[size][size];
		
		for(int y = 0; y < size; ++y) {
			for(int x = 0; x < size; ++x) {
				noise[y][x] = Noise.GenerateNoise(x, y, noiseType) * amplitude;
			}
		}
		
		// start renderer
		DisplayManager.CreateDisplay();
		
		ModelLoader  loader = new ModelLoader();
		StaticShader shader = new StaticShader();
		EntityRenderer renderer = new EntityRenderer(shader);
		
		// TODO: generate a plane and then apply to each vertex 
		//       its height.
		//
		// [width * height] where the vertices are filled in by 
		// generated noise matrix. And then the quad_indices or
		// triangles will then connected these together two at
		// a time. Do this in the terrain class!
		
		System.out.println(GL11.glGetString(GL11.GL_VERSION));
		
		Terrain terrain = new Terrain(size, noise);
		RawModel model = loader.loadToVAO(terrain.getVertices(), terrain.getTriangles(), terrain.getUvs());
		TexturedModel t_model = new TexturedModel(
				model, 
				new ModelTexture(loader.loadTexture("creative-commons-license-symbol")));
		Vector3f position = new Vector3f(0, 0, -1);
		
		Entity entity = new Entity(t_model, position, 270, 0, 0, scale);
		
		Camera camera = new Camera(0.2f);
		
		while(!Display.isCloseRequested()) {
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
