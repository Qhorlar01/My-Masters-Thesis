% Define given parameter values
Ceq = 1e-4;         % Equivalent capacitance [F]
VO  = 48;           % Output voltage [V]
RO  = 4.608;        % Output resistance [Ohm]
IL1 = 17.9;         % Inductor current [A]
DC  = 0.7;          % Duty cycle (D_C)
CO  = 1e-4;         % Capacitance [F]
RC  = 10e-3;        % Resistance [Ohm]
LLk = 32e-6;        % Product L*L_k [H^2]
RL  = 3.43e-3;      % Resistance [Ohm]

%------------------------------------------------------------------
% The given transfer function is:
%
%         s*Ceq*VO + VO/RO + 2*IL1*(1-DC)*(1 + CO*RC*s)
% G_id(s)= -----------------------------------------------------
%         s^2*LLk*Ceq + s*(LLk/RO + Ceq*RL) + RL/RO + 2*(1-DC)^2*(1+CO*RC*s)
%
% We expand both numerator and denominator.
%------------------------------------------------------------------

% Numerator:
% Expand: s*Ceq*VO + VO/RO + 2*IL1*(1-DC) + 2*IL1*(1-DC)*CO*RC*s
% Grouping the s-terms and constant terms gives:
% s-coefficient: Ceq*VO + 2*IL1*(1-DC)*CO*RC
% constant:      VO/RO + 2*IL1*(1-DC)
num_s = Ceq * VO + 2 * IL1 * (1 - DC) * CO * RC;
num_const = VO/RO + 2 * IL1 * (1 - DC);
numerator = [num_s, num_const];

% Denominator:
% Expand: s^2*LLk*Ceq + s*(LLk/RO + Ceq*RL) + RL/RO + 2*(1-DC)^2 + 2*(1-DC)^2*CO*RC*s
% Grouping the s^2, s, and constant terms gives:
% s^2-coefficient: LLk*Ceq
% s-coefficient:   LLk/RO + Ceq*RL + 2*(1-DC)^2*CO*RC
% constant:        RL/RO + 2*(1-DC)^2
den_s2 = LLk * Ceq;
den_s = LLk/RO + Ceq * RL + 2 * (1 - DC)^2 * CO * RC;
den_const = RL/RO + 2 * (1 - DC)^2;
denominator = [den_s2, den_s, den_const];

% Create the transfer function G_id(s)
G_id = tf(numerator, denominator);

% Display the transfer function
disp('The transfer function G_{id}(s) is:');
G_id

margin(G_id)
grid on

% Optionally, you can plot the step response or frequency response:
% step(G_id);
% bode(G_id);
