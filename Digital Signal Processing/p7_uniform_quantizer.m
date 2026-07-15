f = 5;

t = 0:0.001:1;
x = sin(2*pi*f*t);

bits = 3;
L = 2^bits;

xmin = min(x);
xmax = max(x);

delta = (xmax - xmin)/(L - 1);

xq = round((x - xmin)/delta)*delta + xmin;

plot(t,x)
hold on
plot(t,xq)
grid on
title('Input vs Quantized Output')
xlabel('Time')
ylabel('Amplitude')
