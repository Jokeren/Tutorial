
public class NYPizzaStore extends PizzaStore {

    public PizzaIngredientFactory  myNYPizzaIngredientFactory = 
    		new NYPizzaIngredientFactory();

	@Override
	protected Pizza createPizza(String style) {
		// TODO Auto-generated method stub
		Pizza pizza = null;
		if (style.equals("cheese")) {
			pizza = new CheesePizza(myNYPizzaIngredientFactory);
			pizza.setName("NY Cheese Pizza");
		}
		return pizza;
	}

}