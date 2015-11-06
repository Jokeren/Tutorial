public abstract class PizzaStore {

  public Pizza orderPizza(String style) {
	  Pizza pizza;
	  
	  pizza = createPizza(style);
	  
	  pizza.prepare();
	  pizza.bake();
	  pizza.cut();
	  pizza.box();

	  System.out.println(pizza.getName() + " is ordered");
	  return pizza;
  }

  protected abstract Pizza createPizza(String style);

}