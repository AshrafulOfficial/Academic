fs = 1000;
t = 0:1/fs:1;
x = sin(2*pi*10*t) + 3;         

x_filtered = x - mean(x);        

subplot(2,1,1)
plot(t, x)
grid on
title('Original Signal (with DC offset)')
xlabel('t')
ylabel('Amplitude')

subplot(2,1,2)
plot(t, x_filtered)
grid on
title('Filtered Signal (DC removed)')
xlabel('t')
ylabel('Amplitude')
