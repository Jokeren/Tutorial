public class Whip extends CondimentDecorator {

	Beverage beverage;
	public Whip(Beverage beverage) {
		this.beverage = beverage;
	}
	public String getDecription() {
		// TODO Auto-generated method stub
		return beverage.getDescription() + " Whip";
	}

	@Override
	public double cost() {
		// TODO Auto-generated method stub
		return 0.9 + beverage.cost();
	}
}