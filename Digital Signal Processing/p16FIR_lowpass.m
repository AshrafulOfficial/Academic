fs = 1000;
t = 0:1/fs:1;
x = sin(2*pi*10*t) + sin(2*pi*200*t);   
noisy = x + 0.5*randn(size(t));         

fc = 50;                                 
b = fir1(20, fc/(fs/2));                  
filtered = filter(b, 1, noisy);

subplot(2,1,1)
plot(t, noisy)
grid on
title('Noisy Signal (Before Filtering)')
xlabel('t')
ylabel('Amplitude')

subplot(2,1,2)
plot(t, filtered)
grid on
title('Filtered Signal (Low-Pass, After)')
xlabel('t')
ylabel('Amplitude')
