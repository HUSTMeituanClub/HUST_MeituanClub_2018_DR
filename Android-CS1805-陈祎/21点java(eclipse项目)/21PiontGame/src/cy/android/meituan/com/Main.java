package cy.android.meituan.com;

import java.util.Scanner;

public class Main {
	static int turn = 1;
	static int leftPoker = 52;
	static int fetchPoker = 0;
	
	
	public static void main(String[] args) {		
		
		/*生成一副牌组*/
		Poker[] poker = new Poker[52];
		for(int i = 0;i < leftPoker;i ++)
			poker[i] = new Poker(i);
		
		/*洗牌*/
		Judge h = new Judge();
		h.wash(poker);
		
		/*创建角色*/
		Gambler boss = new Gambler("庄家");
		Gambler player = new Gambler("玩家");
		
		/*处理第一轮*/
		h.claim(turn);
		System.out.println(boss.getName()+":");
		boss.fetch(poker[fetchPoker], leftPoker);
		System.out.println(player.getName()+":");
		player.fetch(poker[fetchPoker], leftPoker);
		
		while((boss.getState()!= 1)&&(player.getState()!=-1)) {
			h.claim(turn);
			System.out.println(boss.getName()+":");
			choose(boss, poker);
			System.out.println(player.getName()+":");
			choose(player, poker);			

			//结算阶段
			h.check(boss, player);
		}

		//遍历牌组
//		for(Poker p : poker)
//			System.out.println(p.getState());
	}
	
	static void choose (Gambler g, Poker[] p){
		Scanner s = new Scanner(System.in);
		System.out.println("是否接受本轮发牌？(1.接受.2.放弃.)");
		System.out.print("你的选择是:");
		int num = s.nextInt();
		
		switch (num) {
		case 1:
			g.fetch(p[fetchPoker], leftPoker);
			break;
		case 2:
			g.giveUp();
			System.out.println("你放弃抽牌的机会！");
			break;
		}
	}
	
	
}
