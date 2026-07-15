f = 5;

t = 0:0.001:1;
x = sin(2*pi*f*t);

bits1 = 2;
bits2 = 4;
bits3 = 8;

L1 = 2^bits1;
L2 = 2^bits2;
L3 = 2^bits3;

xmin = min(x);
xmax = max(x);

delta1 = (xmax - xmin)/(L1 - 1);
delta2 = (xmax - xmin)/(L2 - 1);
delta3 = (xmax - xmin)/(L3 - 1);

xq1 = round((x - xmin)/delta1)*delta1 + xmin;
xq2 = round((x - xmin)/delta2)*delta2 + xmin;
xq3 = round((x - xmin)/delta3)*delta3 + xmin;

e1 = x - xq1;
e2 = x - xq2;
e3 = x - xq3;

mse1 = mean(e1.^2);
mse2 = mean(e2.^2);
mse3 = mean(e3.^2);

subplot(4,1,1)
plot(t,x)
grid on
title('Original Signal')

subplot(4,1,2)
plot(t,xq1)
grid on
title('Quantized Signal using 2 bits')

subplot(4,1,3)
plot(t,xq2)
grid on
title('Quantized Signal using 4 bits')

subplot(4,1,4)
plot(t,xq3)
grid on
title('Quantized Signal using 8 bits')

mse1
mse2
mse3
