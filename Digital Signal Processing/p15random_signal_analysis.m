x = randn(1, 1000);        

m  = mean(x);
v  = var(x);
sd = std(x);

subplot(2,1,1)
plot(x)
grid on
title('White Gaussian Noise')
xlabel('n')
ylabel('x[n]')

subplot(2,1,2)
histogram(x)
grid on
title('Distribution of Noise')
xlabel('Value')
ylabel('Frequency')

disp(['Mean: ' num2str(m)])
disp(['Variance: ' num2str(v)])
disp(['Std Dev: ' num2str(sd)])
