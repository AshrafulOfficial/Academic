fs = 1000;
t = 0:1/fs:1;

f1 = 50;
f2 = 120;
f3 = 200;

x = sin(2*pi*f1*t) + sin(2*pi*f2*t) + sin(2*pi*f3*t);

N = length(x);

X = fft(x);

f = (0:N-1)*(fs/N);

subplot(2,1,1)
plot(t,x)
grid on
title('Composite Signal')
xlabel('Time')
ylabel('Amplitude')

subplot(2,1,2)
plot(f, abs(X))
grid on
title('Magnitude Spectrum')
xlabel('Frequency')
ylabel('Magnitude')
