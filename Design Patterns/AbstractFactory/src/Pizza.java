public abstract class Pizza {

  String name;

  Dough dough;

  abstract void prepare();

  public void bake() {
  }

  public void cut() {
  }

  public void box() {
  }

  public void setName(String name) {
	  this.name = name;
  }
  
  public String getName() {
	  return this.name;
  }
}