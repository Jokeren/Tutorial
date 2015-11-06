
public class NYPizzaStore extends PizzaStore {

  protected Pizza createPizza(String type) {
	  if (type.equals("Cheese")) {
		  return new NYStyleCheesePizza();
	  }
	  return null;
  }

}