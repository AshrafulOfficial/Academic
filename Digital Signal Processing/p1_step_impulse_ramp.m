subplot(3,2,1)
n = -5:5;
unit = (n>=0);
stem(n, unit)

grid on
title('Unit Step Signal')
xlabel('n')
ylabel('u[n]')

subplot(3,2,2)
n = -5:5;
impulse = (n == 0);
stem(n, impulse)

grid on
title('Unit Impulse Signal')
xlabel('n')
ylabel('delta[n]')

subplot(3,2,3)
n = -5:5;
ramp = n.*unit;
stem(n, ramp)

grid on
title('Ramp Signal')
xlabel('n')
ylabel('nu[n]')

subplot(3,2,4)
t = 0:0.01:4*pi;
sine_wave = sin(t);
plot(t, sine_wave)

grid on
title('Sine Wave')
xlabel('t')
ylabel('sin(t)')

subplot(3,2,5)
t = 0:0.001:4*pi;
cosine_wave = cos(t);
plot(t, cosine_wave)

grid on
title('Cosine Wave')
xlabel('n')
ylabel('cos(t)')
