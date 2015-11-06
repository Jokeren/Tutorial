
public class Test {
	public static void main(String args[]) {

		WeatherData weather = new WeatherData();
		CurrentConditionDisplay curDisplay = 
				new CurrentConditionDisplay(weather);
		weather.setMeasurements(1.0f, 1.0f, 1.0f);
		weather.setMeasurements(3.0f, 1.0f, 1.0f);
		weather.setMeasurements(4.0f, 1.0f, 1.0f);
		weather.setMeasurements(5.0f, 1.0f, 1.0f);
		weather.setMeasurements(7.0f, 1.0f, 1.0f);
	}
}
