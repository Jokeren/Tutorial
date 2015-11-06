import java.util.Iterator;

public interface MenuComponent {
    
  public String getName();
  
  public void setName(String name);
  
  public void addComponent(MenuComponent menuComponent);

  public Iterator createIterator();

}