package shaders;

import org.lwjgl.util.vector.Matrix4f;
import MathUtility.MathUtility;
import entities.Camera;

public class StaticShader extends ShaderProgram {

	public static final String VERTEX_FILE = "src/shaders/vertex_shader.txt";
	public static final String FRAGMENT_FILE = "src/shaders/fragment_shader.txt";

	private int location_transformationMatrix;
	private int location_projectionMatrix;
	private int location_viewMatrix;
	
	public StaticShader() {
		super(VERTEX_FILE, FRAGMENT_FILE);
	}

	@Override
	protected void bindAttributes() {
		super.bindAttribute(0, "position");
		super.bindAttribute(1, "textureCoords");
	}

	@Override
	protected void getAllUniformLocations() {
		location_transformationMatrix = super.getUniformLocation("transformationMatrix");
		location_projectionMatrix = super.getUniformLocation("projectionMatrix");
		location_viewMatrix = super.getUniformLocation("viewMatrix");
	}
	
	public void loadTransformationMatrix(Matrix4f matrix) {
		super.loadMatrix(location_transformationMatrix, matrix);
	}
	
	public void loadProjectionMatrix(Matrix4f projection) {
		super.loadMatrix(location_projectionMatrix, projection);
	}
	
	public void loadViewMatrix(Camera camera) {
		Matrix4f viewMatrix = MathUtility.createViewMatrix(camera);
		super.loadMatrix(location_viewMatrix, viewMatrix);
	}
}