import java.util.Iterator;

public class Waitress {

	public MenuComponent allMenus;

	public Waitress(MenuComponent allMenus) {
		this.allMenus = allMenus;
	}
	
	public void print() {
		Iterator iterator = allMenus.createIterator();
		printMenu(iterator);
	}

	private void printMenu(Iterator iterator) {
		while (iterator.hasNext()) {
			MenuComponent menuComponent = (MenuComponent) iterator.next();
			System.out.println(menuComponent.getName());
		}
	}

}