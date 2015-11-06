public class Test {
	public static void main(String args[]) {
		Light light = new Light();
		CD cd = new CD();
		DVD dvd = new DVD();
		TV tv = new TV();
		HomeTheaterFacade homeTheater = new HomeTheaterFacade(light, tv, dvd,
				cd);
		
		homeTheater.watchMovie();
		System.out.println("----------");
		homeTheater.endMovie();
	}
}
