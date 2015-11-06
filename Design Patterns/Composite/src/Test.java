
public class Test {
	public static void main(String args[]) {
		MenuComponent all = new Menu();
		MenuComponent subFirst = new Menu();
		MenuComponent subSecond = new Menu();
		MenuComponent subSubFirst = new MenuItem();
		
		all.setName("All Menus");
		subFirst.setName("First Sub Menu");
		subSecond.setName("Second Sub Menu");
		subSubFirst.setName("SubMenu of First Sub Menu");
		all.addComponent(subFirst);
		all.addComponent(subSecond);
		subFirst.addComponent(subSubFirst);
		
		Waitress waitress = new Waitress(all);
		
		waitress.print();
	}
}
