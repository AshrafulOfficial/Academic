f = 10;

t = 0:0.001:1;
x = sin(2*pi*f*t);

fs1 = 2*f;
fs2 = 5*f;
fs3 = 1.2*f;

t1 = 0:1/fs1:1;
t2 = 0:1/fs2:1;
t3 = 0:1/fs3:1;

x1 = sin(2*pi*f*t1);
x2 = sin(2*pi*f*t2);
x3 = sin(2*pi*f*t3);

subplot(3,1,1)
plot(t,x)
hold on
stem(t1,x1)
grid on
title('Nyquist Rate')

subplot(3,1,2)
plot(t,x)
hold on
stem(t2,x2)
grid on
title('Above Nyquist Rate')

subplot(3,1,3)
plot(t,x)
hold on
stem(t3,x3)
grid on
title('Below Nyquist Rate')
