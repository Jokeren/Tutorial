
public class Test {
	public static void main(String args[]) {
		Beverage beverage = new DarkRoast();
		
		Beverage first = new Milk(beverage);
		Beverage second = new Soy(first);
		
		System.out.println(second.cost());
	}
}
