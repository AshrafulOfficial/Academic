fs = 1000;
t = 0:1/fs:1;
x = sin(2*pi*10*t) + sin(2*pi*200*t);

fc = 50;
order = 4;
[b, a] = butter(order, fc/(fs/2), 'low');   
filtered = filter(b, a, x);

subplot(2,1,1)
plot(t, x)
grid on
title('Original Signal')
xlabel('t')
ylabel('Amplitude')

subplot(2,1,2)
plot(t, filtered)
grid on
title('Filtered Signal (Butterworth IIR)')
xlabel('t')
ylabel('Amplitude')
