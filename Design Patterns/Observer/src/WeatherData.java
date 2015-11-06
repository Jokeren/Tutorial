import java.util.ArrayList;

public class WeatherData implements Subject {

	private ArrayList<Observer> observers;
	
	private float temperature;
	
	private float humidity;
	
	private float pressure;
	
	public WeatherData() {
		observers = new ArrayList<Observer>();
	}
	
	public void setMeasurements(float temperature, float humidity, float pressure) {
		this.setTemperature(temperature);
		this.setHumidity(humidity);
		this.setPressure(pressure);
		measurementsChanged();
	}
	
	public void measurementsChanged() {
		notifyObserver();
	}

	@Override
	public void notifyObserver() {
		// TODO Auto-generated method stub
		for (Observer o : observers) {
			o.update(temperature, humidity, pressure);
		}
	}
	
	@Override
	public void registerObserver(Observer o) {
		// TODO Auto-generated method stub
		observers.add(o);
	}

	@Override
	public void removeObserver(Observer o) {
		// TODO Auto-generated method stub
		observers.remove(o);
	}

	public float getTemperature() {
		return temperature;
	}

	public void setTemperature(float temperature) {
		this.temperature = temperature;
	}

	public float getHumidity() {
		return humidity;
	}

	public void setHumidity(float humidity) {
		this.humidity = humidity;
	}

	public float getPressure() {
		return pressure;
	}

	public void setPressure(float pressure) {
		this.pressure = pressure;
	}

}