import java.util.Iterator;

public class Waitress {
	Menu pancakeMenu;
	Menu dinerMenu;

	public Waitress(Menu pancakeMenu, Menu dinerMenu) {
		this.pancakeMenu = pancakeMenu;
		this.dinerMenu = dinerMenu;
	}

	public void printMenu() {
		Iterator pancakeMenuIterator = pancakeMenu.createIterator();
		Iterator dinerMenuIterator = dinerMenu.createIterator();
		
		printMenu(pancakeMenuIterator);
		
		printMenu(dinerMenuIterator);
	}

	private void printMenu(Iterator<?> iterator) {
		while (iterator.hasNext()) {
			MenuItem menuItem = (MenuItem) iterator.next();
			System.out.println(menuItem.getName());
		}
	}

}