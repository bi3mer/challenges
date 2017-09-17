package RenderEngine;

import java.nio.FloatBuffer;
import java.util.List;
import java.util.ArrayList;

import javax.swing.text.html.HTML.Attribute;

import org.lwjgl.BufferUtils;
import org.lwjgl.opengl.GL11;
import org.lwjgl.opengl.GL15;
import org.lwjgl.opengl.GL20;
import org.lwjgl.opengl.GL30;

public class ModelLoader {
	private List<Integer> vaos = new ArrayList<Integer>();
	private List<Integer> vbos = new ArrayList<Integer>();
	
	public RawModel loadToVAO(float[] positions) {
		int vaoID = createVAO();
		storeDataInAttributeList(0, positions);
		unbindVAO();
		return new RawModel(vaoID, positions.length / 3);
	} 
	
	private int createVAO() {
		int gaoID = GL30.glGenVertexArrays();
		vaos.add(gaoID);
		
		GL30.glBindVertexArray(gaoID);
		return gaoID;
	}
	
	private void storeDataInAttributeList(int attributeNumber, float[] data) {
		int vboID = GL15.glGenBuffers();
		vbos.add(vboID);
		
		GL15.glBindBuffer(GL15.GL_ARRAY_BUFFER, vboID);
		FloatBuffer buffer = storeDataInFloatBuffer(data);
		GL15.glBufferData(GL15.GL_ARRAY_BUFFER, buffer, GL15.GL_STATIC_DRAW);
		GL20.glVertexAttribPointer(attributeNumber, 3, GL11.GL_FLOAT, false, 0, 0);
		GL15.glBindBuffer(GL15.GL_ARRAY_BUFFER, 0);
	}
	
	public void cleanUp() {
		for(int i = 0; i < vaos.size(); ++i) {
			GL30.glDeleteVertexArrays(vaos.get(i));
		}
		
		for(int i = 0; i < vbos.size(); ++i) {
			GL30.glDeleteVertexArrays(vbos.get(i));
		}
	}
	
	private void unbindVAO() {
		GL30.glBindVertexArray(0);
	}
	
	private FloatBuffer storeDataInFloatBuffer(float[] data) {
		FloatBuffer buffer = BufferUtils.createFloatBuffer(data.length);
		buffer.put(data);
		buffer.flip();
		return buffer;
	}
}
