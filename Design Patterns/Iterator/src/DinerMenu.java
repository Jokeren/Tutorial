import java.util.ArrayList;
import java.util.Iterator;

public class DinerMenu implements Menu {

	public ArrayList<MenuItem> menuItems;

	public DinerMenu() {
		menuItems = new ArrayList<MenuItem>();
		MenuItem menuItem = new MenuItem();
		menuItem.setName("Diner 1");
		menuItems.add(menuItem);
	}
	
	@Override
	public Iterator createIterator() {
		// TODO Auto-generated method stub
		return menuItems.iterator();
	}

	@Override
	public void addItem() {
		// TODO Auto-generated method stub

	}

}