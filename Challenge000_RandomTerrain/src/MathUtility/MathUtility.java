package MathUtility;

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
}