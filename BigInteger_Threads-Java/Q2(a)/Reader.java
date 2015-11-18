import java.util.Random;

public class Reader extends Thread{
	
	public int no;
	static int number;
	Integer mp;
	public Reader(int no){
		this.no = no;
		mp=new Integer(3);
	}

	@Override
	public void run(){
		Random randomint = new Random();
		int randomi = randomint.nextInt(30000);	
		synchronized(mp){	
		try{
			mp.wait(randomi);
		}catch(InterruptedException e){ }
		++number;
		System.out.println("Reader "+no+" is entering, Number of Readers: "+number);		
		try{
			mp.wait(5000);
		}catch(InterruptedException e){ }
		--number;
		}
		System.out.println("Reader "+no+" is leaving, Number of Readers: "+number);
		}	
	}		

