%===================================================
%  Solve for Kpv and Kiv using numerical solver
%===================================================

clear; clc;

%% Define parameters
DC  = 0.7;        % Duty cycle D_C
VO  = 48;         % Output voltage V_O [V]
RL  = 3.43e-3;    % Resistance R_L [Ohm]
Ro  = 4.608;      % Resistance R_o [Ohm]
IL1 = 17.9;       % Inductor current I_{L1} [A]
Co  = 1e-4;       % Capacitance C_o [F]
RC  = 10e-3;      % Resistance R_C [Ohm]
C_eq = 1e-4;      % Equivalent capacitance [F]
LLk = 32e-6;      % Inductance [H]
w_zf = 2*(22/7)*500;  % Zero frequency (rad/s)
phi_m = 60;       % Desired phase margin in degrees

%% Define symbolic variables for controller gains and s
syms s Kpv Kiv real

%% Define intermediate symbolic expressions
beta1  = -(1 - DC);
gamma1 = VO;
delta1 = -RL;

beta2  = -1/Ro;
gamma2 = -2 * IL1 * (1 + Co * RC * s);
delta2 = 2 * (1 + Co * RC * s) * (1 - DC);

%% Substitute s = 1i*w_zf (numeric frequency point)
s_val = 1i*w_zf;

%% Define the new transfer function G_vi(s)
% Numerator: s*gamma2*LLk + delta2*gamma1 - delta1*gamma2
num = s * gamma2 * LLk + delta2 * gamma1 - delta1 * gamma2;

% Denom: s*gamma1*C_eq + beta1*gamma2 - beta2*gamma1
den = s * gamma1 * C_eq + beta1 * gamma2 - beta2 * gamma1;

G_vi = num / den;
disp('The new transfer function G_vi(s) is:');
pretty(G_vi)

% Evaluate G_vi at s = 1i*w_zf (numeric value)
G_vi_val = subs(G_vi, s, s_val);
disp('G_vi(s) evaluated at s = 1i*w_zf is:');
pretty(G_vi_val)

%% Define the open-loop transfer function with the PI controller:
% G(s) = ((s*Kpv + Kiv)/s)*G_vi(s)
% At s = s_val, this becomes:
Gs_val = ((s_val*Kpv + Kiv)/s_val) * G_vi_val;
disp('The open-loop transfer function G(s) evaluated at s = 1i*w_zf is:');
pretty(Gs_val)

%% Set the design requirement
% For a phase margin of 60°, the desired open-loop phase is (60 - 180) = -120°.
G_des = exp(-1i*120*pi/180);  % Desired complex value (magnitude 1, phase -120°)

%% Form the design equation:
% We require that G_vi_val*(Kpv + Kiv/s_val) = G_des.
eq_complex = G_vi_val*(Kpv + Kiv/s_val) == G_des;

%% Separate into real and imaginary parts
eq_real = real(G_vi_val*(Kpv + Kiv/s_val)) == real(G_des);
eq_imag = imag(G_vi_val*(Kpv + Kiv/s_val)) == imag(G_des);

%% Solve numerically using vpasolve
sol = vpasolve([eq_real, eq_imag], [Kpv, Kiv]);

Kpv_sol = sol.Kpv;
Kiv_sol = sol.Kiv;

disp('Solution for Kpv:');
disp(Kpv_sol);
disp('Solution for Kiv:');
disp(Kiv_sol);
