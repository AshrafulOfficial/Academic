x = [1 2 3 4 5];
n = -2:2;

xr = fliplr(x);

xe = (x + xr)/2;
xo = (x - xr)/2;

subplot(3,1,1)
stem(n,x)
title('Original x[n]')
grid on

subplot(3,1,2)
stem(n,xe)
title('Even Part')
grid on

subplot(3,1,3)
stem(n,xo)
title('Odd Part')
grid on
