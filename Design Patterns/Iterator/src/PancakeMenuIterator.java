import java.util.Iterator;

public class PancakeMenuIterator implements Iterator<MenuItem> {
	private MenuItem[] menuItems;
	private int position = 0;

	public PancakeMenuIterator(MenuItem[] menuItems) {
		this.menuItems = menuItems;
	}

	@Override
	public boolean hasNext() {
		// TODO Auto-generated method stub
		if (position >= menuItems.length || menuItems[position] == null) {
			return false;
		} else {
			return true;
		}
	}

	@Override
	public MenuItem next() {
		// TODO Auto-generated method stub
		MenuItem menuItem = menuItems[position];
		position = position + 1;
		return menuItem;
	}

	@Override
	public void remove() {
		// TODO Auto-generated method stub
		if (position <= 0) {
			throw new IllegalStateException("Can't remove last one");
		}
		if (menuItems[position - 1] != null) {
			for (int i = position - 1; i < (menuItems.length - 1); i++) {
				menuItems[i] = menuItems[i + 1];
			}
			menuItems[menuItems.length - 1] = null;
		}
	}
}