
public class CurrentConditionDisplay implements Observer, DisplayElement {
	private float temperature;
	
	private float humidity;
	
	private float pressure;
	
    private Subject weatherData;

    public CurrentConditionDisplay(Subject weatherData) {
    	weatherData.registerObserver(this);
    	this.weatherData = weatherData;
    }
    
	@Override
	public void update(float temperature, float humidity, float pressure) {
		// TODO Auto-generated method stub
		this.temperature = temperature;
		this.humidity = humidity;
		this.pressure = pressure;
		display();
	}

	@Override
	public void display() {
		// TODO Auto-generated method stub
		System.out.println("Temperature : " + temperature + 
							"Humidity : " + humidity + 
							"pressure : " + pressure);
	}

}