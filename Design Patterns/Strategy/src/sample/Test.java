package sample;

public class Test {
	public static void main(String args[]) {
		Duck mallardDuck = new MallardDuck();
		Duck modelDuck = new ModelDuck();
		
		mallardDuck.performFly();
		mallardDuck.performQuack();
		modelDuck.performFly();
		modelDuck.performQuack();
	}
}
