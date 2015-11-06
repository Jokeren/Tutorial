
public class Test {
	public static void main(String args[]) {
		GumballMachine machine = new GumballMachine(2);
		
		machine.insert();
		machine.turnCrank();
		
		machine.insert();
		machine.turnCrank();
		
		machine.insert();
		machine.turnCrank();
	}
}
