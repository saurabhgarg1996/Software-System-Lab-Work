public class Writer extends Thread{
	
	Integer mp = new Integer(3);
	@Override
	public void run(){
		for (int j=0; j<5; j++){
			synchronized(mp){
		   System.out.println("Writer is entering");					
			try{
				mp.wait(10000);
			}catch(InterruptedException e){ }
			Book.write();			
			try{
				mp.wait(2000);
			}catch(InterruptedException e){ }
			System.out.println("Writer is leaving");
			}
		}

	}
}
		
		
