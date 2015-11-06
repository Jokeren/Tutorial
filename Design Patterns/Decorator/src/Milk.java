public class Milk extends CondimentDecorator {

	Beverage beverage;

	public Milk(Beverage beverage) {
		this.beverage = beverage;
	}
	@Override
	public String getDecription() {
		// TODO Auto-generated method stub
		return beverage.getDescription() + " Milk";
	}

	@Override
	public double cost() {
		// TODO Auto-generated method stub
		return 0.5 + beverage.cost();
	}

}