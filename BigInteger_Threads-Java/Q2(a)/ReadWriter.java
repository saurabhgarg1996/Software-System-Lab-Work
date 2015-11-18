public class ReadWriter {

	public static void main(String[] args){ 	
		Book a = new Book();
		Reader[] mythread = new Reader[20];
		Writer mywrit = new Writer();
		for (int i=0; i<20; i++){
			mythread[i] = new Reader(i+1);
		}
		for (int i=0; i<20; i++){
			mythread[i].start();
		}
		mywrit.start();
	}
}
