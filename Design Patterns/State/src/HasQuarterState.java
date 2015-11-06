

public class HasQuarterState implements State {

	private GumballMachine  gumballMachine;

    public HasQuarterState(GumballMachine machine) {
    	this.gumballMachine = machine;
    }
    
	@Override
	public void insertQuarter() {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void ejectQuarter() {
		// TODO Auto-generated method stub
		System.out.println("eject");
		gumballMachine.setSate(gumballMachine.getNoQuarterState());
	}

	@Override
	public void turnCrank() {
		// TODO Auto-generated method stub
		System.out.println("turn crank");
		gumballMachine.setSate(gumballMachine.getSoldState());
	}

	@Override
	public void dispense() {
		// TODO Auto-generated method stub
		
	}

}