fs = 8000;
t = 0:1/fs:3;
t1 = t(1:fs);
t2 = t((fs+1):2*fs);
t3 = t((2*fs+1):end);
a = 1.2;
f1 = 200;
f2 = 300;
f3 = 400;

S1 = a*sin(2*pi*f1*t1);
S2 = a*sin(2*pi*f2*t2);
S3 = a*sin(2*pi*f3*t3);

S = [S1, S2, S3];
plot(t, S);
sound(S, fs);