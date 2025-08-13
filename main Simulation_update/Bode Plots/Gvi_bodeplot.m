% Define numerator and denominator
num = [-1.1456e-9, -0.00111692, 28.677206];
den = [0, 0.00481074, 21.1567];
% Create the transfer function
G = tf(num, den);
% Display the Transfer Function
disp('The transfer function G_{vi}(s) is:');
G
% Bode plot and margin calculations
margin(G)
grid on