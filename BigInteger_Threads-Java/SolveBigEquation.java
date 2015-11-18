import java.math.*;
import java.util.Scanner;
public class SolveBigEquation {
	BigInteger factorial(int n){
		BigInteger fact = new BigInteger("1");
		for (int i=1;i<=n;i++)
		{
			fact = fact.multiply(new BigInteger(i + ""));
		}
		return fact;
	}
	BigDecimal NthRoot(BigInteger num,int n)
	{
		BigDecimal root,prev,abs_value,check;
		root = new BigDecimal("0");
		prev = new BigDecimal("1");
		abs_value = new BigDecimal("1");
		check = new BigDecimal("0.0000001");
		int res ;
		BigDecimal num1 = new BigDecimal(num); 
		res = abs_value.compareTo(check);
		while (res!=-1) {
			root = prev.multiply(new BigDecimal(n-1));
			root=root.divide(new BigDecimal(n),3,RoundingMode.HALF_UP);
			BigDecimal temp = new BigDecimal("1");
			temp = num1.divide(prev.pow(n-1),3,RoundingMode.HALF_UP); 
			temp = temp.divide(new BigDecimal(n),3,RoundingMode.HALF_UP); 
			root = root.add(temp);
			abs_value = root.subtract(prev);
			abs_value = abs_value.abs();
			res = abs_value.compareTo(check);
			prev = root;
		}
		return root;		
	}
	public static void main(String[] args){
		BigDecimal ans_a_1,ans_a_2,ans_a_3,ans_a_4,ans_b_1,ans_b_2,ans_b_3,ans_b_4,temp;
		ans_b_4 = new BigDecimal("0");
		ans_b_3 = new BigDecimal("0");
		ans_b_2 = new BigDecimal("0");
		ans_b_1 = new BigDecimal("0");
		ans_a_4 = new BigDecimal("0");
		ans_a_3 = new BigDecimal("0");
		ans_a_2 = new BigDecimal("0");
		ans_a_1 = new BigDecimal("0");
		temp = new BigDecimal("0");
		BigInteger temp1;
		temp1 = new BigInteger("0");
		
		SolveBigEquation a = new SolveBigEquation();
		BigDecimal fact_50 = new BigDecimal(a.factorial(50));
		BigDecimal fact_100 = new BigDecimal(a.factorial(100));
		
		BigInteger fact_50_1 = new BigInteger("1");
		BigInteger fact_100_1 = new BigInteger("1");
		fact_100_1 = a.factorial(100);
		fact_50_1 = a.factorial(50);
		fact_50_1 = fact_50_1.pow(2);
		temp1 = fact_50_1.add(fact_100_1.multiply(new BigInteger("4")));
		temp = a.NthRoot(temp1,2);
		
		ans_a_1 = ans_a_1.subtract(fact_50);
		ans_a_1 = ans_a_1.subtract(temp);
		ans_a_1 = ans_a_1.divide(new BigDecimal(2),3,RoundingMode.HALF_UP);
		ans_b_1 = ans_b_1.add(fact_50);
		ans_b_1 = ans_b_1.subtract(temp);
		ans_b_1 = ans_b_1.divide(new BigDecimal(2),3,RoundingMode.HALF_UP);
		
		ans_a_2 = ans_a_2.add(fact_50);
		ans_a_2 = ans_a_2.subtract(temp);
		ans_a_2 = ans_a_2.divide(new BigDecimal(2),3,RoundingMode.HALF_UP);
		ans_b_2 = ans_b_2.subtract(fact_50);
		ans_b_2 = ans_b_2.subtract(temp);
		ans_b_2 = ans_b_2.divide(new BigDecimal(2),3,RoundingMode.HALF_UP);
		
		ans_a_3 = ans_a_3.subtract(fact_50);
		ans_a_3 = ans_a_3.add(temp);
		ans_a_3 = ans_a_3.divide(new BigDecimal(2),3,RoundingMode.HALF_UP);
		ans_b_3 = ans_b_3.add(fact_50);
		ans_b_3 = ans_b_3.add(temp);
		ans_b_3 = ans_b_3.divide(new BigDecimal(2),3,RoundingMode.HALF_UP);
		
		ans_a_4 = ans_a_4.add(fact_50);
		ans_a_4 = ans_a_4.add(temp);
		ans_a_4 = ans_a_4.divide(new BigDecimal(2),3,RoundingMode.HALF_UP);
		ans_b_4 = ans_b_4.subtract(fact_50);
		ans_b_4 = ans_b_4.add(temp);
		ans_b_4 = ans_b_4.divide(new BigDecimal(2),3,RoundingMode.HALF_UP);
			 
		System.out.println("The Roots are : ");
		//System.out.println(a.factorial(5));
		System.out.println(ans_a_1 +" , " + ans_b_1);
		System.out.println(ans_a_2 +" , " + ans_b_2);
		System.out.println(ans_a_3 +" , " + ans_b_3);
		System.out.println(ans_a_4 +" , " + ans_b_4);
			
	}
}
