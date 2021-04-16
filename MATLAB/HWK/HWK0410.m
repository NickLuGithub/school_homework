I = imread('peppers.png');
h2 = fspecial('unsharp')
x = I;
x = imfilter(I,h2);
x = rgb2gray(x);

[~, threshold] = edge(x, 'sobel');
fudgeFactor = .5;
y = edge(x,'sobel', threshold * fudgeFactor);
figure;

subplot(1, 3, 1), imshow(I);
subplot(1, 3, 2), imshow(x);
subplot(1, 3, 3), imshow(y);