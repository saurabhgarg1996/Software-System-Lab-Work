public class Writer extends Thread
{
	public Book book;

	public Writer(Book B)
	{
		this.book=B;
	}

	@Override
	public void run () 
   	{	synchronized(book)
   		{ 
   		  		while(book.geti()<5)
		  		{	
	  				book.write(this);
	  			}	
	  			System.exit(0);
	  	}	
   	}
}
