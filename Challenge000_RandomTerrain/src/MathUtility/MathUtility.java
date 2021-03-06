package MathUtility;

import org.lwjgl.util.vector.Matrix4f;
import org.lwjgl.util.vector.Vector3f;

import entities.Camera;

public class MathUtility {
	// linearly interpolate between a and b where the
	// returned value determined by the weight
	// 
	// // weight must be between 0 and 1
	public static float Lerp(float a, float b, float weight) {
		weight = MathUtility.Clamp(a, b, weight);
		
		return (1.0f - weight) * a + weight*b;
	}
	
	// Clamp the value between the min and max
	public static float Clamp(float min, float max, float val) {
		if( min > max) {
			float temp = min;
			min = max;
			max = temp;
		}
		
		if(val > max) {
			val = max;
		} else if(val < min)
		{
			val = min;
		}
		
		return val;
	}
	
	public static Matrix4f createTransformationMatrix(
			Vector3f translation, 
			float rx, 
			float ry, 
			float rz, 
			float scale) {
		Matrix4f matrix = new Matrix4f();
		matrix.setIdentity();
		
		Matrix4f.translate(translation, matrix, matrix);
		Matrix4f.rotate((float) Math.toRadians(rx), new Vector3f(1, 0, 0), matrix, matrix);
		Matrix4f.rotate((float) Math.toRadians(ry), new Vector3f(0, 1, 0), matrix, matrix);
		Matrix4f.rotate((float) Math.toRadians(rz), new Vector3f(0, 0, 1), matrix, matrix);
		Matrix4f.scale(new Vector3f(scale, scale, scale), matrix, matrix);
		
		return matrix;
	}
	
	public static Matrix4f createViewMatrix(Camera camera) {
		Matrix4f viewMatrix = new Matrix4f();
		viewMatrix.setIdentity();
		
		// TODO: could add roll to make this more complete
		Matrix4f.rotate((float) Math.toRadians(camera.getPitch()), new Vector3f(1, 0, 0), viewMatrix,
				viewMatrix);
		Matrix4f.rotate((float) Math.toRadians(camera.getYaw()), new Vector3f(0, 1, 0), viewMatrix, viewMatrix);
		Vector3f cameraPos = camera.getPosition();
		Vector3f negativeCameraPos = new Vector3f(-cameraPos.x,-cameraPos.y,-cameraPos.z);
		Matrix4f.translate(negativeCameraPos, viewMatrix, viewMatrix);
		
		return viewMatrix;
	}
}