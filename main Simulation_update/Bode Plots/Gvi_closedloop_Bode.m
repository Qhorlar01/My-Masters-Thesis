% Clear workspace and command window (optional good practice)
clear; clc;

% Define 's' as a Laplace variable in the Control System Toolbox:
s = tf('s');

% --- 1) Specify your PI gains:
Kp_v = 0.19515136894466927417157273709949;
Ki_v = 2760.3463394718531282697598096881;

% --- 2) Define the PI controller: C(s) = (Kp_i*s + Ki_i)/s
C = (Kp_v*s + Ki_v) / s;

% --- 3) Define the identified plant G_iv(s):

numGvi = [-1.1456e-9, -0.00111692, 28.677206];
denGvi = [0, 0.00481074, 21.1567];
G_vi   = tf(numGvi, denGvi);

% --- 4) Form the unity-feedback closed-loop transfer function:
%         G_CL(s) = (C(s)*G_id(s)) / (1 + C(s)*G_id(s))
G_CLv = feedback(C*G_vi, 1);

% --- 5) Plot the Bode plot of the closed-loop system:
figure;
bode(G_CLv);
grid on;
title('Bode Diagram Gm = inf, Pm = 120.1 deg (at 3.14e+03 ras/s )');
