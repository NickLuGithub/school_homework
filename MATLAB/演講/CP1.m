% 2020.05.15
% LU YUDA
% 聲音練習

%% 

% 取樣頻率
fs = 8000;
% 時間
t = 0:1/fs:3;
% 震幅
a = 1.2;
% 週期
f = 200;
S = a*sin(2*pi*f*t);

plot(t, S);
sound(S, fs);

%% 
mask = ones(size(S));
mask(1*fs:2*fs) = 0;
S_b = S.*mask;
plot(t, S_b);
sound(S_b, fs);

%% 
n = randn(size(S_b)) * 0.3;
S_b_n = S_b + n;
plot(t, S_b_n);
sound(S_b_n, fs);