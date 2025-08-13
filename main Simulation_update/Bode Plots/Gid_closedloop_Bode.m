% Clear workspace and command window (optional good practice)
clear; clc;

% Define 's' as a Laplace variable in the Control System Toolbox:
s = tf('s');

% --- 1) Specify your PI gains:
Kp_i = 0.017517507046631820515065278573513;
Ki_i = 274.94156643134033925127925829284;

% --- 2) Define the PI controller: C(s) = (Kp_i*s + Ki_i)/s
C = (Kp_i*s + Ki_i) / s;

% --- 3) Define the identified plant G_id(s):
%         G_id(s) = (4.81074e-3 * s + 21.15667)
%                  / (3.2e-9 * s^2 + 7.46744e-6 * s + 0.180744)
numGid = [4.81074e-3, 21.15667];
denGid = [3.2e-9, 7.46744e-6, 0.180744];
G_id   = tf(numGid, denGid);

% --- 4) Form the unity-feedback closed-loop transfer function:
%         G_CL(s) = (C(s)*G_id(s)) / (1 + C(s)*G_id(s))
G_CL = feedback(C*G_id, 1);

% --- 5) Plot the Bode plot of the closed-loop system:
figure;
bode(G_CL);
grid on;
title('Bode Diagram Gm = inf, Pm = 120 deg (at 3.14e+04 ras/s )');
