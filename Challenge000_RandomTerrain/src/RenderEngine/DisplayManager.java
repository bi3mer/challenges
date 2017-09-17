package RenderEngine;

import org.lwjgl.LWJGLException;
import org.lwjgl.opengl.ContextAttribs;
import org.lwjgl.opengl.Display;
import org.lwjgl.opengl.DisplayMode;
import org.lwjgl.opengl.GL11;
import org.lwjgl.opengl.GL30;
import org.lwjgl.opengl.PixelFormat;

public class DisplayManager {
	
	public static final int width  = 1280;
	public static final int height = 720;
	public static final int fps_cap = 60;
	public static final String title = "Terrain Generator";
	
	public static void CreateDisplay() {
		ContextAttribs attribs = new ContextAttribs(3, 2)
				.withForwardCompatible(true)
				.withProfileCore(true);
		
		try {
			Display.setDisplayMode(new DisplayMode(width, height));
			Display.create(new PixelFormat(), attribs);
			Display.setTitle(title);
		} catch (LWJGLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		// use whole viewport
		GL11.glViewport(0, 0, width, height);
	}
	
	public static void UpdateDisplay() {
		Display.sync(fps_cap);
		Display.update();
	}
	
	public static void CloseDisplay() {
		Display.destroy();
	}
}
