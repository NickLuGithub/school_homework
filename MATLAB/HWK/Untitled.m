x=imread('peppers.png');

h2=fspecial('unsharp');
imfilter(x,h2);
[~, threshold] = edge(x, 'sobel');
fudgeFactor = .5;
BWs = edge(I,'sobel', threshold * fudgeFactor);
figure, imshow(BWs);

subplot(1, 3, 1), imshow(x);
subplot(1, 3, 1), imshow(BWs);