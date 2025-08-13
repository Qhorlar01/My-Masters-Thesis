%===================================================
%  Solve for Kpi and Kii using numerical solver
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
C_eq = 1e-4;
LLk = 32e-6;
w_zf = 2*(22/7)*5e3;
phi_m = 60;       % Desired phase margin in degrees

%% Define symbolic variables for controller gains and s
syms s Kpi Kii real

%% Define intermediate symbolic expressions
beta1  = -(1 - DC);
gamma1 = VO;
delta1 = -RL;

beta2  = -1/Ro;
gamma2 = -2 * IL1 * (1 + Co * RC * s);
delta2 = 2 * (1 + Co * RC * s) * (1 - DC);

%% Substitute s = 1i*w_zf (numeric frequency point)
s_val = 1i*w_zf;

%% Define the inner transfer function G_id(s)
% Numerator: s*C_eq*gamma1 - beta2*gamma1 + beta1*gamma2
% Denom: s^2*LLk*C_eq - s*(LLk*beta2 + C_eq*delta1) + (delta1*beta2 - delta2*beta1)
numerator = s * C_eq * gamma1 - beta2 * gamma1 + beta1 * gamma2;
denom     = s^2 * LLk * C_eq - s * (LLk * beta2 + C_eq * delta1) + (delta1 * beta2 - delta2 * beta1);
G_id    = numerator / denom;
% Display the result
disp('The transfer function G_id(s) is:');
pretty(G_id)

G_id_val = subs(G_id, s, s_val);  % now a numeric complex number

disp('The inner transfer function G_id(s) evaluated at s = 1i*w_zf is:');
pretty(G_id_val)

%% Define the open-loop transfer function with the PI controller:
% G(s) = ((s*Kpi + Kii)/s)*G_id
% At s = s_val, this becomes:
Gs_val = ((s_val*Kpi + Kii)/s_val)*G_id_val;
disp('The open-loop transfer function G(s) evaluated at s = 1i*w_zf is:');
pretty(Gs_val)

%% Set the design requirement
% For a phase margin of 60, the desired open-loop phase is (60 - 180) = -120 degrees.
G_des = exp(-1i*120*pi/180);  % Desired complex value (magnitude 1, phase -120°)

%% Form the design equation:
% We require that G_id_val*(Kpi + Kii/s_val) = G_des.
% (This follows from writing Gs_val = ((s_val*Kpi + Kii)/s_val)*G_id_val.)
eq_complex = G_id_val*(Kpi + Kii/s_val) == G_des;

%% Separate into real and imaginary parts
eq_real = real(G_id_val*(Kpi + Kii/s_val)) == real(G_des);
eq_imag = imag(G_id_val*(Kpi + Kii/s_val)) == imag(G_des);

%% Solve numerically using vpasolve
sol = vpasolve([eq_real, eq_imag], [Kpi, Kii]);

Kpi_sol = sol.Kpi;
Kii_sol = sol.Kii;

disp('Solution for Kpi:');
disp(Kpi_sol);
disp('Solution for Kii:');
disp(Kii_sol);