
public class CheesePizza extends Pizza {

    public PizzaIngredientFactory  myPizzaIngredientFactory;

    public CheesePizza(PizzaIngredientFactory ingredientFacotory) {
    	this.myPizzaIngredientFactory = ingredientFacotory;
    }
    
	@Override
	void prepare() {
		// TODO Auto-generated method stub
		System.out.println("Prepareing CheesePizza");
		dough = myPizzaIngredientFactory.createDough();
	}
    
    

}