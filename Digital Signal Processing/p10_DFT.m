x = [1 2 3 4];

N = length(x);

X_fft = fft(x);

X_manual = zeros(1,N);

for k = 0:N-1
    for n = 0:N-1
        X_manual(k+1) = X_manual(k+1) + x(n+1)*exp(-1j*2*pi*k*n/N);
    end
end

subplot(2,1,1)
stem(abs(X_fft))
grid on
title('DFT using built-in fft')

subplot(2,1,2)
stem(abs(X_manual))
grid on
title('DFT using manual method')

X_fft
X_manual
