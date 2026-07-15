f = 5;

t = 0:0.001:1;
x = sin(2*pi*f*t);

bits = 3;
L = 2^bits;

xmin = min(x);
xmax = max(x);

delta = (xmax - xmin)/(L - 1);

xq = round((x - xmin)/delta)*delta + xmin;

e = x - xq;

mse = mean(e.^2);

subplot(3,1,1)
plot(t,x)
grid on
title('Original Signal')

subplot(3,1,2)
plot(t,xq)
grid on
title('Quantized Signal')

subplot(3,1,3)
plot(t,e)
grid on
title('Quantization Error')

mse
