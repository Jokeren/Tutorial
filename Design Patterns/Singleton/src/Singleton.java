/*
 * Initialization On Demand Holder Idiom
 */
//public class Singleton {
//	private static class InstanceHoler {
//		static final Singleton INSTANCE = new Singleton();
//	}
//	
//	public static Singleton getInstance () {
//		return InstanceHoler.INSTANCE;
//	}
//}

/*
 * Eager initialization
 */
//public class Singleton {
//	private static final Singleton instance = new Singleton();
//	
//	public static Singleton getInstance () {
//		return instance;
//	}
//}

/*
 * Double instance lock checking
 */
public class Singleton {
	private static volatile Singleton instance;
	
	public static Singleton getInstance () {
		if (null == instance) {
			synchronized(Singleton.class) {
				if (null == instance) {
					instance = new Singleton();
				}
			}
		}
		
		return instance;
	}
}