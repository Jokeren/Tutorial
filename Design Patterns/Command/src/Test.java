
public class Test {
	public static void main(String args[]) {
		Light light = new Light();
		Command lightOff = new LightOffCommand(light);
		Command lightOn = new LightOnCommand(light);
		
		RemoteControl remote = new RemoteControl(4);
		remote.setCommand(0, lightOn, lightOff);
		
		remote.onButtonPush(0);
		remote.onButtonPush(0);
		remote.offButtonPush(0);
		remote.offButtonPush(0);
	}
}
