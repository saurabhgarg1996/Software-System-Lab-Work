import java.util.Random;

public class Book
{
	  private static int readcount;
	  public boolean writerthere;
	  private int i;  
	  private int readercount;

 	  public Book(){
	      i = 0;
      	      readercount=0;
    	      writerthere=false;
  	  }
  
	  public void read(Reader R){
		 Book book=new Book();
  		 synchronized(book)
    		 { 
      			try
      			{ 
        			while(writerthere==false && R.donever<2)
          			{   
				    if(R.ver==i)
				    { 
  					Random randomint = new Random();
				        int randomi= randomint.nextInt(5000);
				        this.wait(randomi); 
				    }
            			    else{
				      	      R.donever++;
					      R.ver=i;
					      readercount++;
					      System.out.println("Reader " + R.num + "  is Entering, Number of Readers: " + readercount );
					      System.out.println("Reader "+R.num +" is reading Book Version: "+ i);
					      this.wait(5000);
					      readercount--;
					      System.out.println("Reader " + R.num + "  is Leaving, Number of Readers: " + readercount );
	                           }
                                 } 
      		         }
      			 catch (InterruptedException e) {}	
                  }
        }


	  public void write(Writer W) 
	  {
		   synchronized(this)
	 	   {        try
			    {
				 if(readercount==0)
				 {             
				    writerthere=true;
				    System.out.println("Writer is entering");
				    this.wait(10000); 
				    i++;
				    System.out.println("Writer is leaving");
				}
				if(i!=5){ 
					  writerthere=false;
					  notify();
					  this.wait(2000);
				}
				else
				  System.exit(0);
			    } 
			    catch (InterruptedException e) {}
			    } 
	            }
	  public int geti()
	  { 
		return i;  
	  }

	}
