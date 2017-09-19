package Terrain;

import RenderEngine.ModelLoader;
import models.RawModel;

public class Terrain {
	private int size;
	
	private int[]   triangles;
	private float[] vertices;
	private float[] uvs;
	
	public Terrain(int size, float[][] heightMap) {
		// should use height map later on to define the z coordinate
		this.size = size;
		this.generatePlane(heightMap);
	}
	
	private void generatePlane(float[][] heightMap) {
		// two triangles for every square in the plane with 
		// 3 vertices
		int triangleCount = (size - 1) * (size - 1) * 2 * 3;
		
		// initialize arrays with correct sizes
		triangles = new int[triangleCount];
		vertices  = new float[size * size * 3];
		uvs       = new float[triangleCount];
		
		int counter = 0;
		for(int y = 0; y < size; ++y) {
			for(int x = 0; x < size; ++x) {
				vertices[counter]     = x / (float) size;
				vertices[counter + 1] = y / (float) size;
				vertices[counter + 2] = heightMap[y][x] / (float) size;
				
				counter += 3;
			}
		}
		
		
		// set triangles for the plane by looping through
		// all of the vertices except the last row
		counter = 0;
		for(int y = 0; y < size - 1; ++y) {
			for(int x = 0; x < size - 1; ++x) {
				int y_offset = y * size;
				
				triangles[counter]     = x + y_offset;
				triangles[counter + 1] = x + y_offset + 1;
				triangles[counter + 2] = x + y_offset + size;
				
				triangles[counter + 3] = x + y_offset + 1;
				triangles[counter + 4] = x + y_offset + 1 + size;
				triangles[counter + 5] = x + y_offset + size;
				
				counter += 6;
			}
		}
		
		// set uvs
		counter = 0;
		for(int y = 0; y < size - 1; ++y) {
			for(int x = 0; x < size - 1; ++x) {
				uvs[counter]     = x / (float) (size - 1);
				uvs[counter + 1] = y / (float) (size - 1);
						
				counter += 2;
			}
		}
	}

	public int[] getTriangles() {
		return triangles;
	}

	public void setTriangles(int[] triangles) {
		this.triangles = triangles;
	}

	public float[] getVertices() {
		return vertices;
	}

	public void setVertices(float[] vertices) {
		this.vertices = vertices;
	}

	public float[] getUvs() {
		return uvs;
	}

	public void setUvs(float[] uvs) {
		this.uvs = uvs;
	}
}
