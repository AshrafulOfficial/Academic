f = 5;

t = 0:0.001:1;
x = sin(2*pi*f*t);

fs = 20;
ts = 0:1/fs:1;
xs = sin(2*pi*f*ts);

xr = interp1(ts, xs, t, 'linear');

subplot(3,1,1)
plot(t,x)
grid on
title('Original Signal')

subplot(3,1,2)
stem(ts,xs)
grid on
title('Sampled Signal')

subplot(3,1,3)
plot(t,x)
hold on
plot(t,xr)
grid on
title('Original vs Reconstructed')
