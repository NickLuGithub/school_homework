[y, fs]=audioread('a1.flac');
sound(y, fs)
time=(1:length(y))/fs;	% �ɶ��b���V�q
plot(time, y);	% �e�X�ɶ��b�W���i��