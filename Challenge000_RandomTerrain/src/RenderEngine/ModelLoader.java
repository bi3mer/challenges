package RenderEngine;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.nio.FloatBuffer;
import java.nio.IntBuffer;
import java.util.List;
import java.util.ArrayList;

import javax.swing.text.html.HTML.Attribute;

import org.lwjgl.BufferUtils;
import org.lwjgl.opengl.GL11;
import org.lwjgl.opengl.GL15;
import org.lwjgl.opengl.GL20;
import org.lwjgl.opengl.GL30;
import org.newdawn.slick.opengl.Texture;
import org.newdawn.slick.opengl.TextureLoader;

import models.RawModel;

public class ModelLoader {
	private List<Integer> vaos = new ArrayList<Integer>();
	private List<Integer> vbos = new ArrayList<Integer>();
	private List<Integer> textures = new ArrayList<Integer>();
	
	public RawModel loadToVAO(float[] positions, int[] indices, float[] uvs) {
		int vaoID = createVAO();
		bindIndicesBuffers(indices);
		storeDataInAttributeList(0, 3, positions);
		storeDataInAttributeList(1, 2, uvs);
		unbindVAO();
		
		
		return new RawModel(vaoID, indices.length);
	} 
	
	public int loadTexture(String file_name) {
		Texture texture = null;
		try {
			texture = TextureLoader.getTexture(".png", new FileInputStream("res/" + file_name + ".png"));
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		int textureID = texture.getTextureID();;
		textures.add(textureID);
		
		return textureID;
	}
	
	private int createVAO() {
		int gaoID = GL30.glGenVertexArrays();
		vaos.add(gaoID);
		
		GL30.glBindVertexArray(gaoID);
		return gaoID;
	}
	
	private void storeDataInAttributeList(int attributeNumber, int coordinateSize, float[] data) {
		int vboID = GL15.glGenBuffers();
		vbos.add(vboID);
		
		GL15.glBindBuffer(GL15.GL_ARRAY_BUFFER, vboID);
		FloatBuffer buffer = storeDataInFloatBuffer(data);
		GL15.glBufferData(GL15.GL_ARRAY_BUFFER, buffer, GL15.GL_STATIC_DRAW);
		GL20.glVertexAttribPointer(attributeNumber, coordinateSize, GL11.GL_FLOAT, false, 0, 0);
		GL15.glBindBuffer(GL15.GL_ARRAY_BUFFER, 0);
	}
	
	public void cleanUp() {
		for(int i = 0; i < vaos.size(); ++i) {
			GL30.glDeleteVertexArrays(vaos.get(i));
		}
		
		for(int i = 0; i < vbos.size(); ++i) {
			GL30.glDeleteVertexArrays(vbos.get(i));
		}
		
		for(int i = 0; i < textures.size(); ++i) {
			GL11.glDeleteTextures(textures.get(i));
		}
	}
	
	private void unbindVAO() {
		GL30.glBindVertexArray(0);
	}
	
	private void bindIndicesBuffers(int[] indices) {
		int vboID = GL15.glGenBuffers();
		vbos.add(vboID);
		GL15.glBindBuffer(GL15.GL_ELEMENT_ARRAY_BUFFER, vboID);
		IntBuffer buffer = storeDataInIntBuffer(indices);
		GL15.glBufferData(GL15.GL_ELEMENT_ARRAY_BUFFER, buffer, GL15.GL_STATIC_DRAW);
	}
	
	private IntBuffer storeDataInIntBuffer(int[] data) {
		IntBuffer buffer = BufferUtils.createIntBuffer(data.length);
		buffer.put(data);
		buffer.flip();
		
		return buffer;
	}
	
	private FloatBuffer storeDataInFloatBuffer(float[] data) {
		FloatBuffer buffer = BufferUtils.createFloatBuffer(data.length);
		buffer.put(data);
		buffer.flip();
		return buffer;
	}
}
