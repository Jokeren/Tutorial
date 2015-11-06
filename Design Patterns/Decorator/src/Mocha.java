public class Mocha extends CondimentDecorator {

	Beverage beverage;
	
	public Mocha(Beverage beverage) {
		this.beverage = beverage;
	}
	
	public String getDecription() {
		// TODO Auto-generated method stub
		return beverage.getDescription() + " Mocha";
	}

	@Override
	public double cost() {
		// TODO Auto-generated method stub
		return 0.6 + beverage.cost();
	}
}