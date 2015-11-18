import java.math.*;
import java.util.Scanner;
public class NthRoot {
	BigDecimal NthRoot(BigInteger num,int n)
	{
		BigDecimal root,prev,abs_value,check;
		root = new BigDecimal("0");
		prev = new BigDecimal(Math.pow(num.doubleValue(),1.0/n));
		abs_value = new BigDecimal("1");
		check = new BigDecimal("0.000001");
		int res ;
		BigDecimal num1 = new BigDecimal(num); 
		res = abs_value.compareTo(check);
		while (res!=-1) {
			root = prev.multiply(new BigDecimal(n-1));
			root=root.divide(new BigDecimal(n),6,RoundingMode.HALF_UP);
			BigDecimal temp = new BigDecimal("1");
			temp = num1.divide(prev.pow(n-1),6,RoundingMode.HALF_UP); 
			temp = temp.divide(new BigDecimal(n),6,RoundingMode.HALF_UP); 
			root = root.add(temp);
			abs_value = root.subtract(prev);
			abs_value = abs_value.abs();
			res = abs_value.compareTo(check);
			prev = root;
			//System.out.println(root); 
		}
		return root;		
	}
	public static void main(String[] args) {
		System.out.println("Enter the BigInteger number : ");
		Scanner in1 = new Scanner(System.in);
		BigInteger inp =in1.nextBigInteger();
		System.out.println("Enter value of n : "); 
		Scanner in2 = new Scanner(System.in);
		int num = in2.nextInt();
		NthRoot n = new NthRoot();
		//n.NthRoot(inp,num);
		System.out.println("The " + num +"th root is : " + n.NthRoot(inp,num));
	}
}