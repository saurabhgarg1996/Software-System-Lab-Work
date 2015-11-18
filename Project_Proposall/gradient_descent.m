%octave script to find shortest path to a min
clc;
clear;
x=-10.0;
y=10.0;
a=0.001;
printf("Give input function : ");	
str=scanf("%s","C");
par_x=x;
par_y=y;
z=0.0;	
b=[];
p=[];
k=1;
for x=-10:2:10
	for y=-10*k:2*k:10*k
q=[x y eval(str)];
p=[p;q];
k=k*(-1);
end
end
k=k*(-1);
for y=10:-2:-10
	for x=10*k:-2*k:-10*k
q=[x y eval(str)];
p=[p;q];
k=k*(-1);
end
end
save input.dat p
while(abs(par_x)>10^(-1) && abs(par_y)>10^(-1))
x=par_x;
y=par_y;
der=eval(str);
x=par_x+0.1;
y=par_y;
der_x=eval(str);
der_x=der_x-der;
x=par_x;
y=par_y+0.1;
der_y=eval(str);
der_y=der_y-der;
par_x=par_x-a*der_x/0.1;
par_y=par_y-a*der_y/0.1;
c=[par_x par_y der];
b=[b;c];
%par_x
%par_y
end
save output.dat b;

