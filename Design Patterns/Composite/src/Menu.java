import java.util.ArrayList;
import java.util.Iterator;
import java.util.Vector;

public class Menu implements MenuComponent {

	private String name;

	private ArrayList MenuComponent;

	public Menu() {
		MenuComponent = new ArrayList();
	}
	
	public String getName() {
		return name;
	}

	@Override
	public Iterator createIterator() {
		// TODO Auto-generated method stub
		return new CompositeIterator(MenuComponent.iterator());
	}

	@Override
	public void setName(String name) {
		// TODO Auto-generated method stub
		this.name = name;
	}

	@Override
	public void addComponent(MenuComponent menuComponent) {
		// TODO Auto-generated method stub
		MenuComponent.add(menuComponent);
	}


}