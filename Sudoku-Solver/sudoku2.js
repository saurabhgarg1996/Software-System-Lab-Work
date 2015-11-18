
var cage1= [0, 1];      
    var cage2= [7, 16];
    var cage3= [20, 21, 30];
    var cage4 =[ 36, 27];
    var cage5 =[53,44];
    var cage6 = [56, 47, 55];
    var cage7 = [59, 60, 50];
    var cage8 = [76, 77, 78];
    var cage9 = [2, 3, 4];
    var cage10=[6, 15];
    var cage11 = [8, 17, 26, 35];
    var cage12 = [32, 41, 23];
    var cage13 = [37, 38, 46];
    var cage14 = [64, 73];
    var cage15 = [58,67, 66, 75];
    var cage16 = [61, 62, 70, 71];
    var cage17 = [9, 10, 18, 19];
    var cage18 = [5, 13, 14, 22];
    var cage19 = [33, 24, 25];
    var cage20 = [45, 54, 63, 72];
    var cage21 = [39, 48, 57];
    var cage22 = [51, 52];
    var cage23 =[79, 80];
    var cage24 = [11, 12];
    var cage25 = [28, 29];
    var cage26 = [31, 40, 49];   
    var cage27 = [34, 42, 43];
    var cage28 = [65, 74];
    var cage29 = [68, 69];
    

function verify() {
    var inputval =[];
    var i;
    var k = 32;
    console.log(k);
    for (i = 0; i < 81; i= i + 1) {
        var y = parseInt(document.getElementById("value" + i).value);
	console.log(y);
        if (y < 1 || y > 9) {
            window.alert("You could not solve it. Try again");
            reset();
	
        }
        else {
            inputval.push(y);
        }
    }
    console.log(inputval);
/*    inputval = [2, 1, 5, 6, 4, 7, 3, 9, 8, 3, 6, 8, 9, 5, 2, 1, 7, 4, 7, 9, 4, 3, 8, 1, 6, 5, 2, 5, 8, 6, 2, 7, 4, 9, 3, 1, 1, 4, 2, 5, 9, 3, 8, 6, 7, 9, 7, 3, 8, 1, 6, 4, 2, 5, 8, 2, 1, 7, 3, 9, 5, 4, 6, 6, 5, 9, 4, 2, 8, 7, 1, 3, 4, 3, 7, 1, 6, 5, 2, 8, 9];*/
   var flag = 0;
    var j, k;
    var count = [0, 0, 0, 0, 0, 0, 0, 0, 0];
    for(j=0; j<9; j++){
        for(k=0; k<9; k++){
          count[inputval[9*j+k]-1] = count[inputval[9*j+k]-1] +1;   
        }
        for(k=0; k<9; k++){
          if (count[k] != 1) {
              window.alert("You could not solve it. Try again!");
              reset();
          }
           count[k] =0;
        }
    }
    
    var start = [0, 3, 6,27, 30, 33, 54, 57, 60];
    
    for(i = 0; i < 9; i++){
        for(k=0; k<9; k++){ 
            count[k]=0;
        }
        for (k=start[i]; k<start[i]+27; k+=9){
            for (j=0; j<3; j++){
                count[inputval[k+j]-1]= count[inputval[k+j]-1]+1;
            }
        }
        
        for (k=0; k<9; k++){
            if (count[k] != 1){
                window.alert("You could not solve it. Try again!");
                reset();
            }
        }
    }
    
    /* Arrays to store the cage values */
    var sumCage = [3, 16, 9, 6, 12, 6, 20, 13, 15, 4, 15, 8, 13, 8, 10, 14, 25, 22, 20, 27, 20, 6, 17, 17, 14, 17, 17, 16, 15];      
    
    
 //   var ar = window["cage1"];
   // var text = ar.toString();
//    window.alert(text+"0");
    
    for (i=1; i<=29; i++){
        var sum=0;
        var ar = window["cage"+i];
        //window.alert(ar.length.toString());
        for(j=0; j< ar.length; j++){
            sum = sum + inputval[ar[j]];
        }
        
        if (sum != sumCage[i-1]){
            window.alert("You could not solve it. Try Again!");
            flag=1;
            reset();
        }
    }
    
    if (flag == 0) {
        window.alert("Congrats! You solved it!");
        reset();
    }
    
}

function reset(){

document.getElementById("res").click();

}


    
            
    
    
    
        
