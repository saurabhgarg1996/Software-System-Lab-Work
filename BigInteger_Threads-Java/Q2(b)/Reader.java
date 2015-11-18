import java.util.Random;

public class Reader extends Thread
{	
	public Book book;
	public int ver;
	public int num;	
	public int donever;

	public Reader(Book B, int i) 
	{ 	this.book=B;
		num=i;
		ver=-1;			//stores the version of the book read
		donever=0;		//stores the version done uptill now
	}

	@Override
	public void run ()
    	{ 	
		synchronized(book)
    		{	
			try
	  		{	
	    			while(true)
	    			{	
					if (book.geti() < 5){
						Random randomint = new Random();
		    				int randomi= randomint.nextInt(30000);
			  			book.wait(randomi);
		    				book.read(this);
					}	
	    			}
	    	         }
	    		 catch(InterruptedException e) {}	
    		}
    	}	
   
}
