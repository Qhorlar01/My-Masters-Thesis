% Define numerator and denominator
num = [-2.24e-10, -2.21e-4, 2.51, 7.92e4];
den = [0, 0.00481074, 21.1567, 0];
% Create the transfer function
G = tf(num, den);
% Display the Transfer Function
disp('The transfer function G_{vi}(s) is:');
G
figure;
bode(G);
grid on;
title('Bode Diagram Gm = inf, Pm = 60 deg (at 500 Hz )');