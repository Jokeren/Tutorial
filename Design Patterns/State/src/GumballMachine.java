
public class GumballMachine {
	private int ballCount = 0;
	private State soldOutState;
	private State noQuarterState;
	private State hasQuarterState;
	private State soldState;
	private State state = soldState;

	public GumballMachine(int ballCount) {
		this.ballCount = ballCount;
		setSoldOutState(new SoldOutSate(this));
		setNoQuarterState(new NoQuarterSate(this));
		setHasQuarterState(new HasQuarterState(this));
		setSoldState(new SoldState(this));
		if (ballCount > 0){
			state = noQuarterState;
		}
	}

	public void insert() {
		state.insertQuarter();
	}

	public void eject() {
		state.ejectQuarter();
	}

	public void turnCrank() {
		state.turnCrank();
		state.dispense();
	}

	public void setSate(State state) {
		this.state = state;
	}

	public void release() {
		if (ballCount >= 0) {
			ballCount--;
		}
	}

	public int getCount() {
		return ballCount;
	}

	public State getSoldOutState() {
		return soldOutState;
	}

	public void setSoldOutState(State soldOutState) {
		this.soldOutState = soldOutState;
	}

	public State getHasQuarterState() {
		return hasQuarterState;
	}

	public void setHasQuarterState(State hasQuarterState) {
		this.hasQuarterState = hasQuarterState;
	}

	public State getSoldState() {
		return soldState;
	}

	public void setSoldState(State soldState) {
		this.soldState = soldState;
	}

	public void setNoQuarterState(State noQuarterState) {
		this.noQuarterState = noQuarterState;
	}

	public State getNoQuarterState() {
		return noQuarterState;
	}
}