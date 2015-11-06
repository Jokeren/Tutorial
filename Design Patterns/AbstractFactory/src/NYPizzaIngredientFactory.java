

public class NYPizzaIngredientFactory implements PizzaIngredientFactory {

    public Dough  myThinCrustDough = new ThinCrustDough();

	@Override
	public Dough createDough() {
		return myThinCrustDough;
		// TODO Auto-generated method stub
		
	}

}