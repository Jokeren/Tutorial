public class RemoteControl {

	Command[] onCommand;

	Command[] offCommand;

	int capacity = 0;

	public RemoteControl(int capacity) {
		onCommand = new Command[capacity];
		offCommand = new Command[capacity];

		Command noCommand = new NoCommand();
		for (int i = 0; i < capacity; i++) {
			onCommand[i] = noCommand;
			offCommand[i] = noCommand;
		}
		this.capacity = capacity;
	}

	public void setCommand(int slot, Command onCommand, Command offCommand) {
		if (slot < capacity) {
			this.onCommand[slot] = onCommand;
			this.offCommand[slot] = offCommand;
		}
	}

	public void onButtonPush(int slot) {
		if (slot < capacity) {
			onCommand[slot].execute();
		}
	}

	public void offButtonPush(int slot) {
		if (slot < capacity) {
			offCommand[slot].execute();
		}
	}

}