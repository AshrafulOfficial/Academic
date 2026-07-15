fs = 1000;
t = 0:1/fs:2;

x1 = sin(2*pi*100*t);

x2 = [sin(2*pi*50*t(1:end/2)) sin(2*pi*200*t(end/2+1:end))];

subplot(2,1,1)
spectrogram(x1,128,120,128,fs,'yaxis')
title('STFT of Stationary Signal')

subplot(2,1,2)
spectrogram(x2,128,120,128,fs,'yaxis')
title('STFT of Non-stationary Signal')
