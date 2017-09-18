package entities;

import org.lwjgl.input.Keyboard;
import org.lwjgl.util.vector.Vector3f;

public class Camera {
	private Vector3f position = new Vector3f(0,0,0);
	
	private float pitch;
	private float yaw;
	private float roll;
	
	private Boolean rotateMode = false;
	
	public Camera(){}
	
	public void move() {
		if(Keyboard.isKeyDown(Keyboard.KEY_W)) {
			if(rotateMode)
				pitch += 1;
			else
				position.z -= 0.02f;
		}
		
		if(Keyboard.isKeyDown(Keyboard.KEY_S)) {
			if(rotateMode)
				pitch -= 1;
			else
				position.z += 0.02f;
		}
		
		if(Keyboard.isKeyDown(Keyboard.KEY_A)) {
			if(rotateMode)
				yaw += 1;
			else
				position.x -= 0.02f;
		}
		
		if(Keyboard.isKeyDown(Keyboard.KEY_D)) {
			if(rotateMode)
				yaw -= 1;
			else
				position.x += 0.02f;
		}
		
		if(Keyboard.isKeyDown(Keyboard.KEY_1)) {
			position.y -= 0.02f;
		}
		
		if(Keyboard.isKeyDown(Keyboard.KEY_3)) {
			position.y += 0.02f;
		}
		
		if(Keyboard.isKeyDown(Keyboard.KEY_M))
			rotateMode = !rotateMode;
	}
	
	public Vector3f getPosition() {
		return position;
	}
	public float getPitch() {
		return pitch;
	}
	public float getYaw() {
		return yaw;
	}
	public float getRoll() {
		return roll;
	}
	
}
