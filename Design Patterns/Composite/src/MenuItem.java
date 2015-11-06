import java.util.Iterator;


public class MenuItem implements MenuComponent {

	private String name;

	public String getName() {
		return name;
	}

	@Override
	public Iterator createIterator() {
		// TODO Auto-generated method stub
		return new NullIterator();
	}

	@Override
	public void setName(String name) {
		// TODO Auto-generated method stub
		this.name = name;
	}

	@Override
	public void addComponent(MenuComponent menuComponent) {
		// TODO Auto-generated method stub
		throw new UnsupportedOperationException();
	}


}