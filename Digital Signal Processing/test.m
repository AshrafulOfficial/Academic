Even and Odd Decomposition:
xr(means x reverse) = fliplr(x);
xe = (x + xr)/2;
xo = (x - xr)2;
x = xe + xo;

Reconstructed Signal:
xr = interp1(ts, xs, t, 'linear');

Uniform Quantization:
xq = round((x - min(x))/delta)*delta + min(x);
delta = (maz(x) - min(x))/(2^b -1);
error = x - xq;
Mean Squared Error(MSE): mse1 = mean(error.^2);
Printing: at last just write mse1.

Statistical Measurement: x=[1 2 3 4 5];
Mean - mean(x);
Variance - var(x);
SD - std(x);
Skewness - skewness(x);
Kurtosis - kurtosis(x);

output print:
display(variable)

Correlation and Covariance: x=[1 2 3 4 5]; y=[2 4 6 8 10]
Auto Correlation - xcorr(x);
Cross Correlation - xcorr(x, y);
Covariance - cov(x, y);






