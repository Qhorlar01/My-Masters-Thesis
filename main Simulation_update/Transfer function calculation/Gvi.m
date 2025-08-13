%% Define System Parameters
Ceq = 1e-4;       % Equivalent capacitance [F]
VO  = 48;         % Output voltage [V]
RO  = 4.608;      % Output resistance [Ohm]
IL1 = 17.9;       % Inductor current [A]
DC  = 0.7;        % Duty cycle (D_C)
CO  = 1e-4;       % Capacitance [F]
RC  = 10e-3;      % Resistance [Ohm]
LLk = 32e-6;      % Product L*L_k [H^2]
RL  = 3.43e-3;    % Resistance [Ohm]

%% Define the Laplace variable
s = tf('s');

%% Define Additional Parameters for G_vi(s)
% These are the correct definitions:
alpha1 = 1;
beta1  = -(1 - DC);
gamma1 = VO;
delta1 = -RL;
alpha2 = 0;  % (Not used in this expression)
beta2  = -1/RO;
gamma2 = -2 * IL1 * (1 + CO * RC * s);  % Note the s-dependence
delta2 = 2 * (1 + CO * RC * s) * (1 - DC);

%% Construct the Transfer Function G_vi(s)
% Numerator: s*gamma2*LLk + delta2*gamma1 - delta1*gamma2
num = s * gamma2 * LLk + delta2 * gamma1 - delta1 * gamma2;

% Denominator: s*gamma1*Ceq + beta1*gamma2 - beta2*gamma1
den = s * gamma1 * Ceq + beta1 * gamma2 - beta2 * gamma1;

G_vi = num / den;

%% Display the Transfer Function
disp('The transfer function G_{vi}(s) is:');
G_vi

%% Optional Plots
% To view the Bode plot or step response, uncomment one or both of the lines below:
 margin(G_vi);
% step(G_vi);
