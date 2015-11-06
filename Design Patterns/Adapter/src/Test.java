
public class Test {
	public static void main(String args[]) {
		Turkey turkey = new Turkey();
		TurkeyAdapter duck = new TurkeyAdapter(turkey);
		
		duck.quack();
		duck.fly();
	}
}
