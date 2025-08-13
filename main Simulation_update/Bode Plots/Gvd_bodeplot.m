% Define numerator and denominator
num = [-1.1456e-9, -0.00111792, 28.67721];
den = [3.2e-9, 7.46744e-6, 0.180744];
% Create the transfer function
G = tf(num, den);
% Bode plot and margin calculations
margin(G)
grid on