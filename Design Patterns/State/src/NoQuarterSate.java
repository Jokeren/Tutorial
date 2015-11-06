

public class NoQuarterSate implements State {

	private GumballMachine  gumballMachine;

    public NoQuarterSate(GumballMachine machine) {
    	this.gumballMachine = machine;
    }
    
	@Override
	public void insertQuarter() {
		// TODO Auto-generated method stub
		System.out.println("insert quarter");
		gumballMachine.setSate(gumballMachine.getHasQuarterState());
	}

	@Override
	public void ejectQuarter() {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void turnCrank() {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void dispense() {
		// TODO Auto-generated method stub
		
	}

}