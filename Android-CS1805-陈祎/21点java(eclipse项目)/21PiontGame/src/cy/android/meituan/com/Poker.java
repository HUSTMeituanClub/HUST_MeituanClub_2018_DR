package cy.android.meituan.com;

public class Poker {
	private String hs;
	private int piont;
	private int realPoint;
	
	public Poker(int piont) {
		super();
		int r = (piont%13) + 1;//1-13
		
		if(piont < 13){
			hs = "红桃";			
		}else if(piont < 26){
			hs = "方块";			
		}else if(piont < 39){
			hs = "黑桃";			
		}else hs = "梅花";			
	
		
		if(r == 1) {
			realPoint = 11;
		}else if(r == 11) {
			realPoint = 10;
		}else if(r == 12) {
			realPoint = 10;
		}else if(r == 13) {
			realPoint = 10;
		}else realPoint = r;
		
		this.piont = r;
	}
	
	public String getState() {
		if(piont == 1) {
			return hs+"A"+",点数是"+realPoint;
		}else if(piont == 11){
			return hs+"J"+",点数是"+realPoint;
		}else if(piont == 12) {
			return hs+"Q"+",点数是"+realPoint;
		}else if(piont == 13) {
			return hs+"K"+",点数是"+realPoint;
		}else return hs+piont+",点数是"+realPoint;
	}

	
	public int getRealPoint() {
		return realPoint;
	}

	public String getHs() {
		return hs;
	}

	public void setHs(String hs) {
		this.hs = hs;
	}

	public int getPiont() {
		return piont;
	}

	public void setPiont(int piont) {
		this.piont = piont;
	}

}
