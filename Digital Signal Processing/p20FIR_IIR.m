fs = 1000;

fir_order = 20;
fc = 50;
b_fir = fir1(fir_order, fc/(fs/2));

iir_order = 4;
[b_iir, a_iir] = butter(iir_order, fc/(fs/2), 'low');

[h_fir, f_fir] = freqz(b_fir, 1, 512, fs);
[h_iir, f_iir] = freqz(b_iir, a_iir, 512, fs);

subplot(2,2,1)
plot(f_fir, abs(h_fir))
grid on
title('FIR Magnitude Response')
xlabel('Frequency (Hz)')
ylabel('|H(f)|')

subplot(2,2,2)
plot(f_iir, abs(h_iir))
grid on
title('IIR Magnitude Response')
xlabel('Frequency (Hz)')
ylabel('|H(f)|')

subplot(2,2,3)
plot(f_fir, angle(h_fir))
grid on
title('FIR Phase Response')
xlabel('Frequency (Hz)')
ylabel('Phase (radians)')

subplot(2,2,4)
plot(f_iir, angle(h_iir))
grid on
title('IIR Phase Response')
xlabel('Frequency (Hz)')
ylabel('Phase (radians)')

disp('IIR Filter Poles:')
disp(roots(a_iir))
disp('All pole magnitudes < 1 means stable:')
disp(abs(roots(a_iir)))
