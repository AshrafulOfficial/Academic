x = [1 2 3 4 5];
y = [2 4 6 8 10];

auto_co = xcorr(x);
cross_co = xcorr(x, y);
co = cov(x, y);

subplot(3,1,1)
stem(auto_co)
grid on
title('Auto Correlation x[n]')
xlabel('x')
ylabel('y')

subplot(3,1,2)
stem(cross_co)
grid on
title('Cross Correlation between x[n] and y[n]')
xlabel('x')
ylabel('y')

subplot(3,1,3)
stem(co)
grid on
title('Cross Covariance between x[n] and y[n]')
xlabel('x')
ylabel('y')

display(co)
