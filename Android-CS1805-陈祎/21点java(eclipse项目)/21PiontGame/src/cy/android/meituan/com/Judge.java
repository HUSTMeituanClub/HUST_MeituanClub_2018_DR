package cy.android.meituan.com;

public class Judge {
	private String name = "荷官";
	
	
	public Judge() {
		
	}


	public void wash (Poker[] p) {
		for(int i = p.length;i > 1;i --)
	     {
	        int r = (int)(Math.random()*i);//返回0~i-1中的一个随机数
	        Poker temp;
		    
	        temp = p[i - 1];
		    p[i - 1] = p[r];
		    p[r] = temp;
		    
	     }
	}
	
	void claim(int t) {
		System.out.println("------------------");
		System.out.println(getName()+":现在是第"+t+"轮");
		System.out.println("------------------");
		Main.turn ++;
	}
	
	void check(Gambler a, Gambler b) {
		int s1 = a.getSumPoint();
		int s2 = b.getSumPoint();
		if (s1>21 && s2<22){
			System.out.println(a.getName()+":");
			for(int i = 0;i < (s2/2);i ++)
				System.out.println("你爆点了！玩家获胜。");
			a.setState(-1);
        }else if (s2>21 && s1<22){
        	System.out.println(b.getName()+":");
			for(int i = 0;i < (s1/2);i ++)
				System.out.println("你爆点了！庄家获胜。");
			b.setState(-1);
        }else if(s1>21&&s2>21){
			System.out.println("荷官:由于庄家玩家同时获胜，按规则庄家获胜！");
			b.setState(-1);
        }
		
		if ((a.getState() == 1)&&(b.getState() == 1)) {
			System.out.println(getName()+":"+"由于庄家和玩家同时放弃，现在进入结算阶段...");
			if (s1 == s2){
				System.out.println("push状态:庄家和玩家打成平局！\n");
				a.setState(-1);
				b.setState(-1);
	        }else if(s1 > s2) {
	        	System.out.println("庄家胜利！");
	        	b.setState(-1);
	        }else {
	        	System.out.println("玩家胜利！");
	        	a.setState(-1);
	        }
		}
	}

	public String getName() {
		return name;
	}
	
}
