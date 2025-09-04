x = [-3 -1 0 1 3];
y = x.*x - 3*x;
plot( x, y )
z = x + y*sqrt(-1) ;
plot( z ) %<---- complex values: plot imag vs. real 
 
