public class Soy extends CondimentDecorator {

	Beverage beverage;
	public Soy(Beverage beverage) {
		this.beverage = beverage;
	}
	
	public String getDecription() {
		// TODO Auto-generated method stub
		return beverage.getDescription() + " Soy";
	}

	@Override
	public double cost() {
		// TODO Auto-generated method stub
		return 0.7 + beverage.cost();
	}
}