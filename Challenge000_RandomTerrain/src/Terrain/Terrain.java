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
		
//		setVertices(new float[] {
//			0, 0, 0,  // v01
//			1, 0, 0,  // v1
//			0, 1, 0,  // v2
//			1, 1, 0   // v3
//		});
		
		int counter = 0;
		for(int y = 0; y < size; ++y) {
			for(int x = 0; x < size; ++x) {
				vertices[counter]     = x / (float) size;
				vertices[counter + 1] = y / (float) size;
				vertices[counter + 2] = heightMap[y][x];
				
				counter += 3;
			}
		}
		
		
		// set triangles for the plane by looping through
		// all of the vertices except the last row
		int triangleIndex = 0;
		for(int boxIndex = 0; boxIndex < Math.pow(size - 1, 2); ++boxIndex) {
			// triangle 1
			triangles[triangleIndex]     = boxIndex + 1 + size;
			triangles[triangleIndex + 1] = boxIndex + 1;
			triangles[triangleIndex + 2] = boxIndex;

			// triangle 2
			triangles[triangleIndex + 3] = boxIndex + 1 + size;
			triangles[triangleIndex + 4] = boxIndex ;
			triangles[triangleIndex + 5] = boxIndex+ size;
			
			triangleIndex += 6;
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
		
		
//		setTriangles(new int[] {
//			0, 1, 3,
//			3, 1, 2
//		});
		
		// set uvs for the plane
//		setUvs(new float[] {
//			0f, 0f,
//			0f, 1f,
//			1f, 1f,
//			1f, 0f
//		});
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
