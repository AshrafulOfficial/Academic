fs = 1000;
fc = 50;
order = 4;
[b, a] = butter(order, fc/(fs/2), 'low');

[h, f] = freqz(b, a, 512, fs);   % frequency response calculate

subplot(2,1,1)
plot(f, abs(h))
grid on
title('Magnitude Response')
xlabel('Frequency (Hz)')
ylabel('|H(f)|')

subplot(2,1,2)
plot(f, angle(h))
grid on
title('Phase Response')
xlabel('Frequency (Hz)')
ylabel('Phase (radians)')
