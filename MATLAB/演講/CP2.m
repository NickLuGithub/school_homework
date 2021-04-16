[y, fs]=audioread('a1.flac');
sound(y, fs)
time=(1:length(y))/fs;	% 時間軸的向量
plot(time, y);	% 畫出時間軸上的波形