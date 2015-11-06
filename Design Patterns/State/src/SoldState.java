
public class SoldState implements State {

    private GumballMachine  gumballMachine;

    public SoldState(GumballMachine machine) {
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
		
	}

	@Override
	public void dispense() {
		// TODO Auto-generated method stub
		System.out.println("dispense");
		gumballMachine.release();
		if (gumballMachine.getCount() == 0) {
			gumballMachine.setSate(gumballMachine.getSoldOutState());
		} else {
			gumballMachine.setSate(gumballMachine.getNoQuarterState());
		}
	}

}