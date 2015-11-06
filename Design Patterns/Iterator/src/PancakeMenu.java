import java.util.Iterator;


public class PancakeMenu implements Menu {
	private MenuItem[] menuItems;
	
	public PancakeMenu() {
		menuItems = new MenuItem[2];
		menuItems[0] = new MenuItem();
		menuItems[0].setName("pancake 1");
		menuItems[1] = new MenuItem();
		menuItems[1].setName("pancake 2");
	}
	@Override
	public Iterator createIterator() {
		return new PancakeMenuIterator(menuItems);
		// TODO Auto-generated method stub
	}

	@Override
	public void addItem() {
		// TODO Auto-generated method stub

	}
}