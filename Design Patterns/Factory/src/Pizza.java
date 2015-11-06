import java.util.ArrayList;

public abstract class Pizza {

  String name;

  String dough;

  String sauce;

  ArrayList toppings = new ArrayList();

  public void prepare() {
	  System.out.println("Preparing " + name + 
			  "dough" + dough +
			  "sauce" + sauce);
	  
	  for (int i = 0; i < toppings.size(); i++) {
		  System.out.println(" " + toppings.get(i));
	  }
  }

  public void bake() {
	  System.out.println("bake");
  }

  public void cut() {
	  System.out.println("cut");
  }

  public void box() {
	  System.out.println("box");
  }

  public String getName() {
	  return name;
  }

}