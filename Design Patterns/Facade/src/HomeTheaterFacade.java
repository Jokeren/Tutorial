public class HomeTheaterFacade {
	private Light light;
	private TV tv;
	private DVD dvd;
	private CD cd;

	public HomeTheaterFacade(Light light, TV tv, DVD dvd, CD cd) {
		this.dvd = dvd;
		this.cd = cd;
		this.light = light;
		this.tv = tv;
	}

	public void watchMovie() {
		light.on();
		tv.on();
		dvd.on();
		dvd.set();
	}

	public void endMovie() {
		dvd.off();
		tv.off();
		light.off();
	}

}