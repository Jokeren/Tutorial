public class Light {

  public static final int ON = 1;

  public static final int OFF = 2;

  private int state = OFF;
    
  public void on() {
	  if (OFF == state) {
		  System.out.println("Light on");
		  state = ON;
	  } else {
		  System.out.println("Light is already on");
	  }
  }

  public void off() {
	  if (ON == state) {
		  System.out.println("Light off");
		  state = OFF;
	  } else {
		  System.out.println("Light is already off");
	  }
  }

}