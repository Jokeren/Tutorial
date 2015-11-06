public abstract class PizzaStore {
	
  public Pizza orderPizza(String style) {
	  Pizza pizza;
	  
	  pizza = createPizza(style);
	  
	  pizza.prepare();
	  pizza.bake();
	  pizza.cut();
	  pizza.box();
	  
	  return pizza;
  }
  
  protected abstract Pizza createPizza(String type);

}