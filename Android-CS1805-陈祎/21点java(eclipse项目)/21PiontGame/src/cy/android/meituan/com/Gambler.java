package cy.android.meituan.com;

public class Gambler {
	private String name;
	private int state;//0为接受1为放弃
	private int sumPoint;
	
	public Gambler(String name) {
		super();
		this.name = name;
	}

	/**
	 * 抽牌
	 * @param p 接受一张牌的实例
	 * @param lp 接受牌组剩余牌数
	 */
	public void fetch(Poker p, int lp) {
		sumPoint += p.getRealPoint();
		Main.fetchPoker ++;
		Main.leftPoker --;
		System.out.println("你抽到"+p.getState());
		System.out.println("当前总点数为:" + sumPoint);
	}
	public void giveUp() {
		setState(1);
	}
	
	public void printSate() {
		
	}
	
	public int getState() {
		return state;
	}

	public void setState(int state) {
		this.state = state;
	}

	public String getName() {
		return name;
	}

	public int getSumPoint() {
		return sumPoint;
	}
	
	
	

}
