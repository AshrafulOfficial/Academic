x = [2 4 4 4 5 5 7 9];
n = 0:length(x)-1;

m  = mean(x);
v  = var(x);
sd = std(x);
sk = skewness(x);
ku = kurtosis(x);

subplot(3,1,1)
stem(n, x)
grid on
title('Signal x[n] with Mean Reference')
xlabel('n')
ylabel('x[n]')
hold on
yline(m, 'r', 'LineWidth', 2)
legend('x[n]', 'Mean')
hold off

subplot(3,1,2)
values = [m v sd sk ku];
labels = {'Mean','Variance','Std Dev','Skewness','Kurtosis'};
bar(values)
set(gca, 'xticklabel', labels)
grid on
title('Statistical Measures Comparison')
ylabel('Value')


subplot(3,1,3)
histogram(x)
grid on
title(['Distribution of x[n]  (Skewness = ' num2str(sk) ', Kurtosis = ' num2str(ku) ')'])
xlabel('Value')
ylabel('Frequency')

disp('--- Built-in Results ---')
disp(['Mean: ' num2str(m)])
disp(['Variance: ' num2str(v)])
disp(['Std Dev: ' num2str(sd)])
disp(['Skewness: ' num2str(sk)])
disp(['Kurtosis: ' num2str(ku)])


