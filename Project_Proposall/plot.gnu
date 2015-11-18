# Plot of x^2+y^2
set xrange [-15:15]
set yrange [-15:15]
set grid 
set xlabel "X axis" offset -3,-2
set ylabel "Y axis" offset 3,-2
set zlabel "Z axis" offset -5
set title "Gradient descent"
set terminal png size 1780,1560 enhanced font "Helvetica,20"
set output 'plot.png'
splot "input.dat" title 'input functon' with lines,"output.dat" title 'Gradient descent path' with lines
