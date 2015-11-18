// ReaderWriter.java

public class ReadWriter
{
	  public static void main(String args[])
	  {
		    Book book  = new Book();
		    Writer W = new Writer(book); 
		    Reader[] R =new Reader[20];
		    for(int i=0; i<20; i++){   
		        R[i] = new Reader(book,i+1);
			R[i].start();
		    }
			W.start();
	  }
}
