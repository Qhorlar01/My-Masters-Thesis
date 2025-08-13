%------------------------------------------------------------
% Define parameters (either as numeric values or keep symbolic)
% For example, here we define them numerically:
DC  = 0.7;        % Duty cycle D_C
VO  = 48;         % Output voltage V_O [V]
RL  = 3.43e-3;    % Resistance R_L [Ohm]
Ro  = 4.608;      % Resistance R_o [Ohm]
IL1 = 17.9;       % Inductor current I_{L1} [A]
Co  = 1e-4;       % Capacitance C_o [F]
RC  = 10e-3;      % Resistance R_C [Ohm]

%------------------------------------------------------------
% Alternatively, if you want to keep some parameters symbolic,
% uncomment the following line:
% syms DC VO RL Ro IL1 Co RC real

% Define the symbolic variable for s
syms s

%------------------------------------------------------------
% Define the variables based on your equations:
%
%   alpha1 = 1
%   beta1  = -(1 - D_C)
%   gamma1 = V_O
%   delta1 = -R_L
%
%   alpha2 = 0
%   beta2  = -1/R_o
%   gamma2 = -2 I_{L1} (1 + C_o R_C s)
%   delta2 = 2 (1 + C_o R_C s) (1 - D_C)
%------------------------------------------------------------
alpha1 = 1;
beta1  = -(1 - DC);
gamma1 = VO;
delta1 = -RL;

alpha2 = 0;
beta2  = -1/Ro;
gamma2 = -2 * IL1 * (1 + Co * RC * s);
delta2 = 2 * (1 + Co * RC * s) * (1 - DC);

%------------------------------------------------------------
% Display the results
disp('alpha1 = '); disp(alpha1);
disp('beta1 = ');  disp(beta1);
disp('gamma1 = '); disp(gamma1);
disp('delta1 = '); disp(delta1);
disp('alpha2 = '); disp(alpha2);
disp('beta2 = ');  disp(beta2);
disp('gamma2 = '); disp(gamma2);
disp('delta2 = '); disp(delta2);
