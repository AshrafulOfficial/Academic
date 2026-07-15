x = [1 2 3 4];
n = 0:3;

subplot(3,2,1)
stem(n, x)

grid on
title('Original Signal x[n]')
xlabel('n')
ylabel('x[n]')

subplot(3,2,2)
stem(n+2, x)

grid on
title('RightShift Signal x[n-2]')
xlabel('n')
ylabel('Amplitude')

subplot(3,2,3)
stem(n-2, x)

grid on
title('LeftShift Signal x[n+2]')
xlabel('n')
ylabel('Amplitude')

subplot(3,2,4)
stem(n, 2*x);

grid on
title('Time Scaling 2x[n]')
xlabel('n')
ylabel('Amplitude')

subplot(3,2,5)
stem(-n, x);

grid on
title('Reverse Signal x[-n]')
xlabel('n')
ylabel('Amplitude')

