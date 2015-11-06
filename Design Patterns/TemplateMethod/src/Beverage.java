public abstract class Beverage {

  public void prepareRecipe() {
	  bowWater();
	  brew();
	  pourInCup();
	  addCondiments();
  }

  abstract void brew();

  abstract void addCondiments();

  void bowWater() {
	  System.out.println("Bow water!");
  }

  void pourInCup() {
	  System.out.println("Pour in cup!");
  }

}