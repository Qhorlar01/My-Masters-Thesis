% Define numerator and denominator
num = [8.4272e-5, 1.69328, 5816.85];
den = [3.2e-9, 7.46744e-6, 0.180744];
% Create the transfer function
G = tf(num, den);
% Display the Transfer Function
disp('The transfer function G_{vi}(s) is:');
G
figure;
bode(G);
grid on;
title('Bode Diagram Gm = inf, Pm = 60 deg (at 5000 Hz )');