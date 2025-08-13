% Define parameter values (set these to your actual system values)
Ceq = 1e-4;       % Equivalent capacitance [F]
VO  = 48;         % Output voltage [V]
RO  = 4.608;      % Output resistance [Ohm]
IL1 = 17.9;       % Inductor current [A]
DC  = 0.7;        % Duty cycle (D_C)
CO  = 1e-4;       % Capacitance [F]
RC  = 10e-3;      % Resistance [Ohm]
LLk = 32e-6;      % Product L*L_k [H^2]
RL  = 3.43e-3;    % Resistance [Ohm]

%% Numerator Expansion
% The numerator is:
% 2*(1 + CO*RC*s)*[ VO*(1-DC) - IL1*(LLk*s + RL) ]
%
% Expand the bracket:
%    B(s) = VO*(1-DC) - IL1*RL - IL1*LLk*s
%
% Then multiply by (1 + CO*RC*s):
%   (1 + CO*RC*s)*B(s) = [VO*(1-DC) - IL1*RL] ...
%                        + s*[ CO*RC*VO*(1-DC) - CO*RC*IL1*RL - IL1*LLk ] ...
%                        - s^2*(CO*RC*IL1*LLk)
%
% Finally, multiply the whole expression by 2.
%
% This yields:
%   s^2 coefficient: a2 = -2*CO*RC*IL1*LLk
%   s coefficient:   a1 = 2*( -IL1*LLk + CO*RC*VO*(1-DC) - CO*RC*IL1*RL )
%   Constant term:   a0 = 2*( VO*(1-DC) - IL1*RL )
a2 = -2 * CO * RC * IL1 * LLk;
a1 = 2 * ( - IL1 * LLk + CO * RC * VO * (1 - DC) - CO * RC * IL1 * RL );
a0 = 2 * ( VO * (1 - DC) - IL1 * RL );

numerator = [a2, a1, a0];

%% Denominator Expansion
% The denominator is:
% s^2*LLk*Ceq + s*(LLk/RO + RL*Ceq) + RL/RO + 2*(1 + CO*RC*s)*(1-DC)^2
%
% Expand the extra term:
% 2*(1-DC)^2*(1 + CO*RC*s) = 2*(1-DC)^2 + 2*CO*RC*(1-DC)^2*s
%
% Grouping like terms:
%   s^2 coefficient: d2 = LLk * Ceq
%   s coefficient:   d1 = (LLk/RO) + RL*Ceq + 2*CO*RC*(1-DC)^2
%   Constant term:   d0 = RL/RO + 2*(1-DC)^2
d2 = LLk * Ceq;
d1 = (LLk/RO) + RL * Ceq + 2 * CO * RC * (1 - DC)^2;
d0 = (RL/RO) + 2 * (1 - DC)^2;

denominator = [d2, d1, d0];

%% Create the Transfer Function
G_vd = tf(numerator, denominator);

%% Display the Transfer Function
disp('The transfer function G_{vd}(s) is:');
G_vd

%% Optional Plots
% Uncomment the following lines to see the step or Bode plot.
% step(G_vd);
% bode(G_vd);
