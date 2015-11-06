public class DVD implements Instrument {

	@Override
	public void on() {
		// TODO Auto-generated method stub
		System.out.println("DVD on");
	}

	@Override
	public void off() {
		// TODO Auto-generated method stub
		System.out.println("DVD off");
		
	}

	@Override
	public void set() {
		// TODO Auto-generated method stub
		System.out.println("DVD set");
		
	}

	public void unSet() {
		System.out.println("DVD unSet");
		
	}
  
}