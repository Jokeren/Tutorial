
public class SoldOutSate implements State {

	private GumballMachine  gumballMachine;

    public SoldOutSate(GumballMachine machine) {
    	gumballMachine = machine;
    }
    
	@Override
	public void insertQuarter() {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void ejectQuarter() {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void turnCrank() {
		// TODO Auto-generated method stub
		System.out.println("sold out");
	}

	@Override
	public void dispense() {
		// TODO Auto-generated method stub

		System.out.println("sold out");
	}

}